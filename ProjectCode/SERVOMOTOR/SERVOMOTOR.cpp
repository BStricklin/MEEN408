#include "SERVOMOTOR.h"

PWM servoPWM  // (pin_number, period, duty_cycle)

SERVOMOTOR::SERVOMOTOR()
:servoPWM(2, 20000000, 0)
{}

SERVOMOTOR::~SERVOMOTOR() {
}
SERVOMOTOR::int getAngle();

SERVOMOTOR::void setAngle(int Anglee) {
  if ((Anglee<theta_high) && (Anglee>theta_low)) {
    Angle = Anglee;
  } else {
    // error
  }

  int pulsewidth = 0;
  pulsewidth = (upper_limit-lower_limit)/(theta_high-theta_low) * Angle + lower_limit;
  servoPWM.setPWMDutyCycle(pulsewidth);

}

SERVOMOTOR::void gripperOpen() {
  servoPWM.setPWMDutyCycle(upper_limit)
}

SERVOMOTOR::void gripperClose() {
  servoPWM.setPWMDutyCycle(lower_limit)
}
