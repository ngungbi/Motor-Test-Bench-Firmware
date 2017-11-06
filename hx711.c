#include <util/delay.h>
#include "HX711.h"

uint32_t _value[3] = {0,0,0};

void HX711_Init(){
	HX711_PORT = 0x00;
	HX711_DDR = 0x00;
	//HX711_DDR = 1<<3;
	DDRB = 0x07;

	//setBit(HX711_PORT, 3);
	PORTB |= 0x07;
	_delay_ms(1);
	PORTB &= ~0x07;
	//resetBit(HX711_PORT, 3);
}
void HX711_Read(){
	if(HX711_PIN & (1<<2)){
		return;
	}
	for(uint8_t j=0; j<3; j++){
			_value[j] = 0;
		}
	for(uint8_t i=0; i<24; i++){
		//PORTC |= (1<<3);
		PORTB |= 0x07;
		for(uint8_t j=0; j<3; j++){
			_value[j] = _value[j]<<1;
		}
		_value[0] |= (HX711_PIN >> 3) & 1;
		_value[1] |= (HX711_PIN >> 4) & 1;
		_value[2] |= (HX711_PIN >> 5) & 1;
		//PORTC &= ~(1<<3);
		PORTB &= ~0x07;
	}
	PORTB |= 0x07; // 8,9,10 di arduino
	PORTB &= ~0x07;
}
uint32_t HX711_GetValue(uint8_t idx){
	//uint32_t _tmp = _value[idx];
	return _value[idx];
}