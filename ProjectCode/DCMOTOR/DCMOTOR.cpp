#include "DCMOTOR.h"

DCMOTOR::DCMOTOR(int PWMNumberr, int EQEPNumberr)
    : motorPWM(PWMNumberr, 1000000, 0), motorEQEP(EQEPNumberr) {
  // the commands above with : pwmconstructor, eqepconstructor are called an
  // initializer list. We used to initialize the member variables, especially
  // when they are a instances of our own classes
  setk_t(0);
  setk_emf(0);
  // We now unenable the motor
  enable(0);
  // and are done with the constructor.
}
int DCMOTOR::getAngle() {
  return motorEQEP.readPosition(); // return the current EQEP position.
}
void DCMOTOR::setPWMPeriod(int Periodd) {
  motorPWM.setPWMPeriod(Periodd); // set the pwm period in the pwm object
}
int DCMOTOR::getPWMPeriod() {
  return motorPWM.getPWMPeriod(); // get the pwm period from the pwm object
}
void DCMOTOR::setPWMDutyCycle(int DutyCyclee) {
  motorPWM.setPWMDutyCycle(DutyCyclee);
}
int DCMOTOR::getPWMDutyCycle() {
  return motorPWM.getPWMDutyCycle(); // same as getPWMPeriod above
}
double setk_emf(double k_emff) { k_emf = k_emff; }
double getk_emf() { return k_emf; }
double setk_t(double k_tt) { k_t = k_tt; }
double getk_t() { return k_t; }
void DCMOTOR::enable(int enablee) {
  if (enablee != 0) { // so long as the input is not zero, we accept it as enable
    enablee = 1;
  }
  motorPWM.enable(enablee);
}
}
-*
