#ifndef EQEP_H
#define EQEP_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

class EQEP {
private:
  // ADC parameters
  int EQEPPosition;
  int EQEPNumber;
  // filename strings
  std::string EQEPDeviceFile;
  std::string EQEPPositionFile;

public:
  EQEP(int EQEPNumberr);
  int readPosition();
};

#endif
