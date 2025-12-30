#ifndef _MAIN_H
#define _MAIN_H

#include <reg51.h>

#define FREQ (12000000UL)  // 12 MHz
#define OSC_PER_INST (12)

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;

#define INTERRUPT_Timer_0_Overflow 1
#define INTERRUPT_Timer_1_Overflow 3
#define INTERRUPT_Timer_2_Overflow 5

#define DEBOUNCE_PERIOD 100
#define IS_ANODE (bit) 1
#define seg7_number 2

void run();

#define INIT 0
#define PROGRAM_SELECT 1
#define RUN_PROGRAM 2
 
#endif