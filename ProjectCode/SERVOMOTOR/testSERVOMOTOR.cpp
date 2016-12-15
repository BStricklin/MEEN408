#include <unistd.h>
#include <iostream>
#include <string>
#include "DCMOTOR.h"
using namespace std;
int main() {
  cout << " Will this do anything at all?" << endl;
  SERVOMOTOR mySERVO(0, 2, 30, 60);
  cout << "About to start test file" << endl;
  int check = 0;
  cin >> check;

  // Start of Turn One
  myDCMOTOR.enable(0);
  myDCMOTOR.setPWMDutyCycle(50);
  myDCMOTOR.setDirection(1);
  cout << "Start Turn     " << endl;
  cout << "Angle:   " << myDCMOTOR.getAngle() << endl;
  myDCMOTOR.enable(1);
  usleep(500000);
  myDCMOTOR.enable(0);
  usleep(500000);
  cout << "End Turn     " << endl;
  cout << "Angle:   " << myDCMOTOR.getAngle() << endl;
  // End of Turn One

  // Start of Turn Two
  myDCMOTOR.setPWMDutyCycle(50);
  myDCMOTOR.setDirection(-1);
  cout << "\nStart Turn     " << endl;
  cout << "Angle:   " << myDCMOTOR.getAngle() << endl;
  myDCMOTOR.enable(1);
  usleep(500000);
  myDCMOTOR.enable(0);
  usleep(500000);
  cout << "End Turn        " << endl;
  cout << "Angle:   " << myDCMOTOR.getAngle() << endl;
}
