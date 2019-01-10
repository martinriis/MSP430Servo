// *** SERVO CONTROL LIBRARY FOR MSP430 MICROCONTROLLERS *** //
// ********************** MARTIN RIIS ********************* //

#include "MSP430Servo.h"

void setupServo(float angle) {
  float hTime = (angle / 180) + 1; // Calculates PWM high time from angle
  int CCR = (hTime + lTime) * factor; // Capture compare value
  
  // *** OUTPUT PORT CONFIGURATION *** //
  P1DIR |= BIT7; // Sets P1.7 to output
  P1SEL0 |= BIT7; // Connects P1.7 to timer block
  
  // *** TIMER A0 SETUP *** //
  TA0CCR0 = CCR; // PWM period
  TA0CCTL1 |= OUTMOD_7; // Reset/set output
  TA0CCR1 = hTime * factor; // PWM high time
  TA0CCTL2 |= OUTMOD_7; // Reset/set output
  TA0CCR2 = lTime * factor; // PWM low time
  TA0CTL |= TASSEL_2 | MC_1; // SMCLK, up-mode
}
