/*
 * main.h
 *
 *  Created on: 14 Nov 2016
 *      Author: WillyKaze
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "mbed.h"
#include "rtos.h"


extern "C" {
#include "CANopen.h"
}

#define BUS_BITRATE     (500)

#define COB_slave

#ifdef COB_slave
#define LPC_NODEID      (0x02)
#define MFE_NODEID      (0x01)
#else
#define LPC_NODEID      (0x01)
#define MFE_NODEID      (0x02)
#endif

int main(void);

static void tmrTask_thread(void const *args);

static void appTask_thread(void const *args);

void programAysnc(uint16_t timer1msDiff);

void _CANInterruptHandler(void);

#endif /* MAIN_H_ */
