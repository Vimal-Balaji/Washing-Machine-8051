#ifndef _SEVEN_SEGMENT_H
#define _SEVEN_SEGMENT_H

void seg7_display_1_digit(uint8_t digit,bit is_anode);
void seg7_display_digits(uint8_t digits[],bit is_anode);
void seg7_enable(int segment_number,bit is_anode,bit disable_rest);
int array_to_value(uint8_t *container_array, int array_size);

#endif