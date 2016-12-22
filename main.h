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

#define LPC_NODEID      (0x01)
#define SLV_NODEID      (0x02) // Tested with a MicroFlex e100

int main(void);

static void tmrTask_thread(void const *args);

static void appTask_thread(void const *args);

void programAysnc(uint16_t timer1msDiff);

void _CANInterruptHandler(void);

#endif /* MAIN_H_ */
