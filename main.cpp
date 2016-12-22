/*
 * CANopen main program file.
 *
 * This file is a demo program for mbed microcontrollers.
 *
 * @file        main.cpp
 * @author      Benoit Rapidel
 * @copyright   2016 ExMachina
 *
 * This file is part of CANopenNode, an opensource CANopen Stack.
 * Project home page is <https://github.com/CANopenNode/CANopenNode>.
 * For more information on CANopen see <http://wwwdog.can-cia.org/>.
 *
 * CANopenNode is free and open source software: you can redistribute
 * it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://wwwdog.gnu.org/licenses/>.
 *
 * Following clarification and special exception to the GNU General Public
 * License is included to the distribution terms of CANopenNode:
 *
 * Linking this library statically or dynamically with other modules is
 * making a combined work based on this library. Thus, the terms and
 * conditions of the GNU General Public License cover the whole combination.
 *
 * As a special exception, the copyright holders of this library give
 * you permission to link this library with independent modules to
 * produce an executable, regardless of the license terms of these
 * independent modules, and to copy and distribute the resulting
 * executable under terms of your choice, provided that you also meet,
 * for each linked independent module, the terms and conditions of the
 * license of that module. An independent module is a module which is
 * not derived from or based on this library. If you modify this
 * library, you may extend this exception to your version of the
 * library, but you are not obliged to do so. If you do not wish
 * to do so, delete this exception statement from your version.
 */

#include "main.h"

#include "leds.h"
#include "watchdog.h"

extern "C" {
#include "CO_driver.h"
#include "CO_CAN.h"
}

#include "CO_helpers.h"
#include "CO_units.h"

#include "MFE_helpers.h"

#include "debug.h"

#define TMR_TASK_INTERVAL   (1000)          /* Interval of tmrTask thread in microseconds */
#define INCREMENT_1MS(var)  (var++)         /* Increment 1ms variable in tmrTask */


/* Global variables and objects */

Watchdog wdog;

volatile uint16_t   CO_timer1ms = 0U;   /* variable increments each millisecond */

Timer t;

extern "C" void mbed_reset();


/* main ***********************************************************************/
int main (void){
    HBled = 1;
    CANrunLed = 1;
    CANerrLed = 1;
    ERRled = 1;

    Thread tmr_thread;
    Thread app_thread;

    wdog.kick(10); // First watchdog kick to trigger it


    USBport.baud(115200);

    tmr_thread.start(callback(tmrTask_thread, NULL));
    app_thread.start(callback(appTask_thread, NULL));

    CO_NMT_reset_cmd_t reset = CO_RESET_NOT;

    while(reset != CO_RESET_APP){
        /* CANopen communication reset - initialize CANopen objects *******************/
        CO_ReturnError_t err;
        uint16_t timer1msPrevious;

        wdog.kick(); // Kick the watchdog

        /* initialize CANopen */
        err = CO_init(
                (int32_t)0,             /* CAN module address */
                (uint8_t)LPC_NODEID,    /* NodeID */
                (uint16_t)BUS_BITRATE); /* bit rate */

        if(err != CO_ERROR_NO){
            ERRled = 1;

            while(1);
            /* CO_errorReport(CO->em, CO_EM_MEMORY_ALLOCATION_ERROR, CO_EMC_SOFTWARE_INTERNAL, err); */
        }

        CO_CANsetNormalMode(CO->CANmodule[0]);

        /* Configure CAN transmit and receive interrupt */

        CANport->attach(&_CANInterruptHandler, CAN::RxIrq);
        CANport->attach(&_CANInterruptHandler, CAN::TxIrq);

        /* start CAN */

        HBled = 0;
        ERRled = 0;
        CANrunLed = 0;
        CANerrLed = 0;

        reset = CO_RESET_NOT;
        timer1msPrevious = CO_timer1ms;

        wdog.kick(5); // Change watchdog timeout

        while(reset == CO_RESET_NOT) {
            /* loop for normal program execution */

            wdog.kick(); // Kick the watchdog

            uint16_t timer1msCopy, timer1msDiff;
            timer1msCopy = CO_timer1ms;
            timer1msDiff = timer1msCopy - timer1msPrevious;
            timer1msPrevious = timer1msCopy;


            /* CANopen process */
            reset = CO_process(CO, timer1msDiff, NULL);

            /* Nonblocking application code may go here. */

            programAysnc(timer1msDiff);

            Thread::wait(1);
        }
    }


    /* program exit */
    /* stop threads */
    HBled = 1;
    CANrunLed = 1;
    CANerrLed = 1;
    ERRled = 1;

    tmr_thread.terminate();
    app_thread.terminate();


    /* delete objects from memory */
    CO_delete(0/* CAN module address */);


    /* reset */
    mbed_reset();
    return 1;
}


/* timer thread executes in constant intervals ********************************/
static void tmrTask_thread(void const *args){
    while(true) {

        /* sleep for interval */
        Thread::wait(1);

        INCREMENT_1MS(CO_timer1ms);

        if(CO->CANmodule[0]->CANnormal) {
            bool_t syncWas;

            /* Process Sync and read inputs */
            syncWas = CO_process_SYNC_RPDO(CO, TMR_TASK_INTERVAL);

            /* Further I/O or nonblocking application code may go here. */


            /* Write outputs */
            CO_process_TPDO(CO, syncWas, TMR_TASK_INTERVAL);

            /* verify timer overflow */
            if(0) {
                CO_errorReport(CO->em, CO_EM_ISR_TIMER_OVERFLOW, CO_EMC_SOFTWARE_INTERNAL, 0U);
            }

            if(CO_timer1ms % 50 == 0) {
                HBled = !HBled;
            }
        }
    }
}

static void appTask_thread(void const *args){
    uint8_t err = 1;

    while(true) {
        if(CO->CANmodule[0]->CANnormal) {
            uint8_t     dataRx[CO_SDO_BUFFER_SIZE];
            uint8_t     dataTx[CO_SDO_BUFFER_SIZE];
            uint32_t    abortCode=0;
            uint32_t    readSize;
            MFEnode_t   node;

#if (LPC_NODEID == 1) // If the LPC is the master node
            while (err != 0) {
                CO->NMT->operatingState = CO_NMT_PRE_OPERATIONAL;

                CO_sendNMTcommand(CO, CO_NMT_RESET_NODE, MFE_NODEID);

                Thread::wait(5000);

                err = MFE_scan(MFE_NODEID, &node, 100);
                if (err) continue;

                err = MFE_connect(&node, 100);

                CO->NMT->operatingState = CO_NMT_OPERATIONAL;
            }

            abortCode = 0;
            readSize = 0;
            err = CO_SDO_read(MFE_NODEID, 0x3f00, 0x01, dataRx, sizeof(dataRx), &abortCode, &readSize, 100);
            if (readSize == 4) {
                bfloat _temp = { .bytes = { dataRx[0], dataRx[1], dataRx[2], dataRx[3] << 0 }};

                USBport.printf("READ 3f00 1: %f\r\n", _temp.to_float);
                _temp.to_float += 10.0;
                err = CO_SDO_write(MFE_NODEID, 0x3f00, 0x02, _temp.bytes, 4, &abortCode, 100);
                USBport.printf("WRITE 3f80 2: %d %x\r\n", err, swapBytes(abortCode));
            }
#endif
        }

        Thread::wait(500);
    }
}

void programAysnc(uint16_t timer1msDiff) {
    CANrunLed = LED_GREEN_RUN(CO->NMT) ? true : false;
    CANerrLed = LED_RED_ERROR(CO->NMT) ? true : false;
}


/* CAN interrupt function */
void _CANInterruptHandler(void){
    CO_CANinterrupt(CO->CANmodule[0]);
}
