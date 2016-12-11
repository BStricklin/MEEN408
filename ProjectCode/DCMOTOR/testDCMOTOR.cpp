#include "DCMOTOR.h"
#include <unistd.h>

int main()
{
  DCMOTOR myDCMOTOR(0,2);
  myDCMOTOR.enable(1);
  myDCMOTOR.setPWMDutyCycle(0.25);
  usleep(250000);
  myDCMOTOR.enable(0);
}
