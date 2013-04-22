/**
 * @file joystickservo.h
 * @version 0.1
 * @date 10/04/2012
 * @author: Carlos Pereira Atencio
 * 
 * This library interfaces with the PWM internal peripheral and the data
 * coming from the ADC internal peripheral. 
 * 
 * This library has been developed to use a Processor Expert autogenerated
 * code from the PWM1, PWM2, ADC1, and ADC2 components.
 *************************************************************************** */

#ifndef JOYSTICKSERVO_H_
#define JOYSTICKSERVO_H_

#include "common.h"

#define JOYSTICKSERVO_MIN_US 1000
#define JOYSTICKSERVO_MAX_US 2000

uint16 js_AdcToUs(uint16 adc);
void js_SetServoDutyUsX(uint16 us);
void js_SetServoDutyUsY(uint16 us);
void js_Move(void);

#endif /* JOYSTICKSERVO_H_ */