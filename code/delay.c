#include "main.h"
#include "init.h"
#include "delay.h"

void delay_T0_ms(uint16_t N){
    uint16_t ms;
    TMOD&=0xF0;
    TMOD|=0x01;
    ET0=0;

    for(ms=0;ms<N;ms++){
        TH0=PRELOAD1H;
        TL0=PRELOAD1L;
        TF0=0;
        TR0=1;
        while(TF0==0);
        TR0=0;
    }
}

void delay_T1_ms(uint16_t N){
    uint16_t ms;
    TMOD&=0x0F;
    TMOD|=0x10;
    ET1=0;

    for(ms=0;ms<N;ms++){
        TH1=PRELOAD1H;
        TL1=PRELOAD1L;
        TF1=0;
        TR1=1;
        while(TF1==0);
        TR1=0;
    }
}

void delay_loop_ms(uint16_t ms){
    uint16_t counter1;
    uint8_t counter2;
    for(counter1=0;counter1<ms;counter1++){
        for(counter2=0;counter2<ms;counter2++);
    }
}

void delay_loop_ns(uint16_t ns){
    int counter;
    for(counter=0;counter<ns;counter++);
}