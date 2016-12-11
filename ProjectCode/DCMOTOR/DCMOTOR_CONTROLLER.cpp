#include "DCMOTOR_CONTROLLER.h"

DCMOTOR_CONTROLLER::DCMOTOR_CONTROLLER(float k_pp, float k_dd, float k_ii,
                                       int PWMNumberr, int Periodd,
                                       int DutyCyclee, int EQEPNumberr)
    : {
  // check validity of inputs
  k_p = k_pp;
  k_d = k_dd;
  k_i = k_ii;
  PWM myPWM(PWMNumberr, Periodd, DutyCyclee);
  EQEP my EQEP(EQEPNumberr);
};

DCMOTOR_CONTROLLER::~DCMOTOR_CONTROLLER(){

};

void DCMOTOR_CONTROLLER::run(){

};
