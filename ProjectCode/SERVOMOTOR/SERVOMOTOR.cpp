#include "SERVOMOTOR.h"

SERVOMOTOR::SERVOMOTOR() : servoPWM(2, 20000000, 0) {}

// SERVOMOTOR::int getAngle();

void SERVOMOTOR::setAngle(int Anglee) {
  if ((Anglee < theta_high) && (Anglee > theta_low)) {
    Angle = Anglee;
    int pulsewidth = 0;
    pulsewidth =
        (upper_limit - lower_limit) / (theta_high - theta_low) * Angle +
        lower_limit;
    servoPWM.setPWMDutyCycle(pulsewidth);
  } else {
    // error
    std::cout << "Could not set Angle.\n";
  }
}

SERVOMOTOR::void gripperOpen() {
  servoPWM.setPWMDutyCycle(upper_limit)
}

SERVOMOTOR::void gripperClose() {
  servoPWM.setPWMDutyCycle(lower_limit)
}
