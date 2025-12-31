#ifndef _SWITCH_H
#define _SWITCH_H

#define SWITCH_NOT_PRESSED (bit) 0
#define SWITCH_PRESSED     (bit) 1

bit switch_state(int switch_number,uint8_t debounce_period);
bit switch_current_state(int switch_number);

#endif