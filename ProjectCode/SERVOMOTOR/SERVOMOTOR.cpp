#include "SERVOMOTOR.h"

SERVOMOTOR::SERVOMOTOR(int PWMNumberr)
 : servoPWM(PWMNumberr, 20000000, 0) {
  lower_limit=1100000;
  upper_limit=1500000;
  theta_low=0;
  theta_high=90;
}

// SERVOMOTOR::int getAngle();

void SERVOMOTOR::setAngle(int Anglee) {
  if ((Anglee < theta_high) && (Anglee > theta_low)) {
    Angle = Anglee;
    int pulsewidth = 0;
    pulsewidth =
        (upper_limit - lower_limit) / (theta_high - theta_low) * Angle +
        lower_limit;
    servoPWM.setDutyCycle(pulsewidth);
  } else {
    // error
    std::cout << "Could not set Angle.\n";
  }
}

void SERVOMOTOR::gripperOpen() {
  servoPWM.enable(1);
  servoPWM.setDutyCycle(upper_limit); }

void SERVOMOTOR::gripperClose() {
  servoPWM.enable(1);
  servoPWM.setDutyCycle(lower_limit); }

SERVOMOTOR::~SERVOMOTOR() {
  servoPWM.setDutyCycle(upper_limit);
  servoPWM.enable(0); }
