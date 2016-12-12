#include "EQEP.h"
#include <iostream>
#include <unistd.h>

int main() {
  EQEP myEQEP(0);
  std::cout << "EQEP Start" << std::endl;
  for (int i = 0; i < 100; i++) {
    std::cout << "(Angle) : (" << myEQEP.readPosition() << ")" << std::endl;
    usleep(100000);
  }
  std::cout << "EQEP End" << std::endl;
  return 0;
}
