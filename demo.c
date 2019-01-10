// *** SERVO CONTROL DEMO FOR MSP430 MICROCONTROLLERS *** //
// ************ COPYRIGHT 2018 MARTIN RIIS ************* //

#include "MSP430Servo.h"

int main() {
  WDTCTL = WDTPW | WDTHOLD; // Stops watchdog timer
  setupServo(86.83);
  
  __bis_SR_register(LPM0_bits); // Enters low power mode 0 (LPM0)
}