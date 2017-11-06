#ifndef _HX711_
#define _HX711_

#include <stdint.h>
#include "common.h"

#define HX711_PORT PORTC
#define HX711_DDR DDRC
#define HX711_PIN PINC

#define HX711_CLK_HIGH setBit(HX711_DDR, 3);

void HX711_Init(void);
void HX711_Read(void);
void HX711_SetOffset(uint8_t idx, uint8_t offset);
uint32_t HX711_GetValue(uint8_t idx);
#endif