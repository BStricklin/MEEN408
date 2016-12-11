#ifndef DCMOTOR_CONTROLLER_H
#define DCMOTOR_CONTROLLER_H

#include "DCMOTOR.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

class DCMOTOR_CONTROLLER {
private:
  // Controller parameters
  double e;
  double e_i;
  double e_d;
  double e_prev;
  double k_p;
  double k_d;
  double k_i;
  // motor Tracking
  long int AbsCNT;
  long int AbsCNT_Prev;
  long int RelCNT;
  double angle;
  // DC Motor
  DCMOTOR motor;

public:
  DCMOTOR_CONTROLLER();
  ~DCMOTOR_CONTROLLER();
  void run();
};

#endif
