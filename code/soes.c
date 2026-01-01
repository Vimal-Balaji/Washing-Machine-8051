#include "main.h"
#include "soes.h"

uint8_t TL0_Reload=0;
uint8_t TH0_Reload=0;

void soes_voidInit(){
    TMOD|=0x01;
    TL0=0xB0;
    TH0=0x3C;
    EA=1;
    ET0=1;
    TF0=0;
    TR0=1;
}

void soes_voidGoToSleep(void){
    PCON=0x01;
}

void SOES_ISR() interrupt INTERRUPT_Timer_0_Overflow {
	TL0=0xB0;
	TH0=0x3C;
	TF0 = 0;
	TR0 = 1;
	run();
}