#ifndef DCMOTOR_H
#define DCMOTOR_H

#include "../EQEP/EQEP.h"
#include "../PWM/PWM.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

class DCMOTOR {
private:
  // Motor Parameters
  PWM motorPWM;   // pwm to do basic control signal to motor
  EQEP motorEQEP; // for reading back the angle
  double gear_r;  // the motor's gear ratio. Not sure how to use this right now.
  double k_emf;   // emf motor constant  w = k_emf * Voltage
  double k_trq;     // torque constant     Torque = k_trq * current
  // Angle Tracking
  double angle;
  // Control Parameters
  int motorOn;

public:
  DCMOTOR(int PWMNumberr, int EQEPNumberr);
//~DCMOTOR();
  int getAngle();
  void setPWMPeriod(int Periodd);
  int getPWMPeriod();
  void setPWMDutyCycle(int DutyCyclee);
  int getPWMDutyCycle();
  double setk_emf(double k_emff);
  double getk_emf();
  double setk_trq(double k_trqq);
  double getk_trq();
  void enable(int enablee); // disables or enables the motors
};

#endif
