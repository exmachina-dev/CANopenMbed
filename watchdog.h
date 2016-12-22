/* 
 * Code taken from https://developer.mbed.org/forum/mbed/topic/508/
 * Originally writed by Simon Ford
 * */

#ifndef WATCHDOG_H_
#define WATCHDOG_H_

#include "mbed.h"

DigitalOut led(LED1);

class Watchdog {
public:
    void kick(float s) {
        LPC_WDT->WDCLKSEL = 0x1;                // Set CLK src to PCLK
        uint32_t clk = SystemCoreClock / 16;    // WD has a fixed /4 prescaler, PCLK default is /4 
        LPC_WDT->WDTC = s * (float)clk;         
        LPC_WDT->WDMOD = 0x3;                   // Enabled and Reset        
        kick();
    }
    
    void kick() {
        LPC_WDT->WDFEED = 0xAA;
        LPC_WDT->WDFEED = 0x55;
    }
};

#endif
