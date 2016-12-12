#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include "../PWM/PWM.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

class SERVOMOTOR {
private:
  PWM servoPWM; // pwm which will send control signal to servomotor
  int Angle;
  int lower_limit;
  int upper_limit;
  int theta_low;
  int theta_high;

public:
  SERVOMOTOR(int PWMNumberr);
  //  int getAngle();
  void setAngle(int Anglee);
  void gripperOpen();
  void gripperClose();
  ~SERVOMOTOR();
};

#endif
