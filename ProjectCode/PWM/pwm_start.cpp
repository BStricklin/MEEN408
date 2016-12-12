#include "PWM.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
using namespace std;

int main() {
  cout << "Initializing PWM" << endl;

  int input;

  PWM myPWM(0, 1000000, 0);

  cout << "Input Period: ";
  cin >> input;
  myPWM.setPeriod(input);

  cout << endl << "Input Duty Cycle: ";
  cin >> input;
  myPWM.setDutyCycle(input);

  cout << endl << "Enable? (1 or 0) ";
  cin >> input;
  myPWM.enable(input);

  while (input >= 0) {
    cout << "Input Duty Cycle: (type negative number to quit) ";
    cin >> input;
    if (input >= 0) {
      myPWM.setDutyCycle(input);
    }
  }

  return 0;
}
