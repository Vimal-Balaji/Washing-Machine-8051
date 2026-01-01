#include "main.h"
#include "init.h"
#include "washer.h"

uint8_t dry[]={DRY,REPEAT,FINISH};
uint8_t wash[]={ADD_DETERGENT, ADD_WATER, HEAT, SPIN_MOTOR, TOGGLE_MOTOR, DRAIN_WATER, DRY, REPEAT, FINISH};
uint8_t light_wash[]={ADD_DETERGENT, ADD_WATER, HEAT, TOGGLE_MOTOR, DRAIN_WATER, DRY, REPEAT, FINISH};
uint8_t very_light_wash[]={ADD_DETERGENT, ADD_WATER, HEAT, SPIN_MOTOR, DRAIN_WATER, DRY, REPEAT, FINISH};

bit feature_heat;
bit feature_dry;
bit feature_double;

void washer_off_all(){
    motor_fast=OFF;
    motor_slow=OFF;
    motor_reverse=OFF;
    water_drain=OFF;

    door_lock=OFF;
    heater=OFF;
    water_valve=OFF;
    detergent_valve=OFF;

    error=OFF;
}

void washer_program_features(uint8_t program_number,uint8_t *features){
    //features[0]-heat; features[1]=dry; features[2]=double
    if(program_number==6 || program_number==14 || program_number==18){
        features[0]=FALSE;
		features[1]=FALSE;
		features[2]=FALSE; 
    }
    else if(program_number==5 || program_number==13 || program_number==17){
        features[0]=TRUE;
		features[1]=FALSE;
		features[2]=FALSE;
    }
    else if(program_number==1 || program_number==4 || program_number==12 || program_number==16){
        features[0]=FALSE;
		features[1]=TRUE;
		features[2]=FALSE; 
    }
    else if(program_number==3 || program_number==11 || program_number==15){
        features[0]=TRUE;
		features[1]=TRUE;
		features[2]=FALSE;
    }
    else if(program_number==10){
        features[0]=FALSE;
		features[1]=FALSE;
		features[2]=TRUE;
    }
    else if(program_number==9){
        features[0]=TRUE;
		features[1]=FALSE;
		features[2]=TRUE;
    }
    else if(program_number==2 || program_number==8){
        features[0]=FALSE;
		features[1]=TRUE;
		features[2]=TRUE;
    }
    else if(program_number==7){
        features[0]=TRUE;
		features[1]=TRUE;
		features[2]=TRUE;
    }
}

uint8_t washer_get_program_step(uint8_t program_number, int step_number) {
	if(program_number==1 || program_number==2) {
		return dry[step_number];
	} 
    else if(program_number==3 || program_number==4 || program_number==5 || program_number==6 || program_number==7 || program_number==8 || program_number==9 || program_number==10) {
		return wash[step_number];
	} 
    else if(program_number==11 || program_number==12 || program_number==13 || program_number==14) {
		return light_wash[step_number];
	} 
    else if(program_number==15 || program_number==16 || program_number==17 || program_number==18) {
		return very_light_wash[step_number];
	}
}