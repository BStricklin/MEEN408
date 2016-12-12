#include "SERVOMOTOR.h"
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main() {
   cout << "Starting SERVO Test" << endl;
   SERVOMOTOR mySERVO(0); //Initiating SERVO PWM
   cout << "SERVO PWM has been initialized, continue?" << endl;
   int temp;
   cin >> temp;
   cout << "Open 1" << endl;
   mySERVO.gripperOpen();
   cout << "Continue?" << endl;
   cin >> temp;
   cout << "Closing the gripper" << endl;
   mySERVO.gripperClose();
   cout << "Gripper should be closed, continue?" << endl;
   cin >> temp;
   cout << "Opening the gripper" << endl;
   mySERVO.gripperOpen();
   cout << "Gripper should be open. End program?" << endl;
   cin >> temp;
   return 0;
}
