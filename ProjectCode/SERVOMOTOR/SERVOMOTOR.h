#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include "PWM.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

class SERVOMOTOR {
private:
  PWM servoPWM; // pwm which will send control signal to servomotor
  int Angle;
  int lower_limit = 1000000;
  int upper_limit = 1400000;
  int theta_low = 0;
  int theta_high = 90;

public:
  SERVOMOTOR();
  //  int getAngle();
  void setAngle(int Anglee);
  void gripperOpen();
  void gripperClose();
};

#endif
