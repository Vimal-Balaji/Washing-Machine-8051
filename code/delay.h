#ifndef _DELAY_H
#define _DELAY_H


#define PRELOAD1 (65536-(uint8_t)((FREQ/OSC_PER_INST)/1020))  // For 1 ms delay
#define PRELOAD1H (PRELOAD1/256)
#define PRELOAD1L (PRELOAD1%256)

void time_set_value(bit timer,uint8_t ms);

void delay_T0_ms(uint16_t N);
void delay_T1_ms(uint16_t N);

void delay_loop_ms(uint16_t ms);
void delay_loop_ns(uint16_t ns);

#endif