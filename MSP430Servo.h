// *** SERVO CONTROL LIBRARY FOR MSP430 MICROCONTROLLERS *** //
// ************** COPYRIGHT 2018 MARTIN RIIS *************** //

#include <msp430fr4133.h>
#include <float.h>

#define factor 1048.576 // Division factor for converting frequency into TA0CCR0 value
#define lTime 20 // Low time of the PWM signal in ms

void setupServo(float);