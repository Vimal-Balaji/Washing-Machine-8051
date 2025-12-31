#include "main.h"
#include "init.h"
#include "switch.h"
#include "delay.h"

bit switch_state(int switch_number,uint8_t debounce_period){
    bit result=SWITCH_NOT_PRESSED;

    if(switch_current_state(switch_number)==0){
        delay_loop_ms(debounce_period);
        if (switch_current_state(switch_number)==0){
            result=SWITCH_PRESSED;
        }
    }
    return result;
}

bit switch_current_state(int switch_number){
   if(switch_number==1){
		up_pin=1;
		return	up_pin;	
	} 
    else if(switch_number==2){
		down_pin = 1;
		return	down_pin;	
	}
    else if(switch_number==3){
		start_pin = 1;
		return	start_pin;	
	} 
    else {
		return 0;
	}
 
}