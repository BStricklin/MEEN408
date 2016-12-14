#ifndef DCMOTOR_H
#define DCMOTOR_H

#include "../EQEP/EQEP.h"
#include "../GPIO/GPIO.h"
#include "../PWM/PWM.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

class DCMOTOR {
private:
  // Motor Parameters
  PWM motorPWM;       // pwm to do basic control signal to motor
  EQEP motorEQEP;     // for reading back the angle
  GPIO motorHighGPIO; // used to set the motor direcion
  GPIO motorLowGPIO;  // used to set the motor direction
  double gear_r; // the motor's gear ratio. Not sure how to use this right now.
  double k_emf;  // emf motor constant  w = k_emf * Voltage
  double k_trq;  // torque constant     Torque = k_trq * current
  // Motor Tracking
  double angle;
  // Control Parameters
  int motorOn;
  int direction; // 1 = forward, -1 = backward ==>these depend on how you
                 // install the motor

public:
  DCMOTOR(int PWMChipNumberr, int PWMNumberr, int EQEPNumberr, int GPIONumberHigh,
          int GPIONumberLow);
  //~DCMOTOR();
  int getAngle();
  void setPWMPeriod(int Periodd);
  int getPWMPeriod();
  void setPWMDutyCycle(double DutyCyclee);
  int getPWMDutyCycle();
  double setk_emf(double k_emff);
  double getk_emf();
  double setk_trq(double k_trqq);
  double getk_trq();
  void enable(int enablee); // disables or enables the motors
  void setDirection(int directionn);
};

#endif
