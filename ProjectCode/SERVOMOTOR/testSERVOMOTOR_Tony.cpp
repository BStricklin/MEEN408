#include "SERVOMOTOR.h"
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main() {
   cout << "Starting SERVO Test" << endl;
   SERVOMOTOR mySERVO(2); //Initiating SERVO PWM
   cout << "SERVO PWM has been initialized" << endl;

   return 0;
}
