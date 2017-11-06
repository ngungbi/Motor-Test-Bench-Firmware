#include <avr/io.h>
#define setBit(_port,_pin)   (_port) |= (1<<(_pin))
#define resetBit(_port,_pin) (_port) &= ~(1<<(_pin))