#ifndef ADC_H
#define ADC_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

class ADC {
private:
  // ADC parameters
  double ADCVoltage;
  int ADCRawReading;
  int ADCPinNumber;
  int maxRaw = 4095;          // maximum returned bit reading
  int minRaw = 0;             // minimum returned bit reading
  double maxADCVoltage = 1.8; // maximum allowed voltage -- DO NOT EXCEED
  double minADCVoltage = 0.0; // minimum measureable voltage (lowest output)
  // filename strings
  std::string ADCDeviceFile;
  std::string ADCVoltageFile;

public:
  ADC(int ADCPinNumberr);
  double readVoltage();
  int readRaw();
};

#endif
