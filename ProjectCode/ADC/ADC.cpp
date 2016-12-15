// Author: Augustus Ellis
#include "ADC.h"

ADC::ADC(int ADCPinNumberr) {
  // check that inputs are valid - for now we assume they are valid
  // Set internal port parameters
  ADCPinNumber = ADCPinNumberr;

  // Set filename strings
  std::stringstream ss;
  ss << "/sys/bus/iio/devices/iio:device0/";  // ADCDeviceFile
  ADCDeviceFile =
      ss.str();  // put the contents of the stringstream into the device string
  ss.clear();    // clear any status flags on the stringstream
  ss.str(std::string());  // delete the contents of the stringstream so we can
                          // use it again
  ss << ADCDeviceFile << "in_voltage" << ADCPinNumber
     << "_raw";               // ADCVoltageFile
  ADCVoltageFile = ss.str();  // see above for device file
  ss.clear();                 //
  ss.str(std::string());      //
}

double ADC::readVoltage() {
  int rawADC = readRaw();  // get the raw bit voltage reading from the adc pin
                           // using a function defined below
  ADCVoltage = ((maxADCVoltage - minADCVoltage) / (maxRaw - minRaw)) * rawADC +
               minADCVoltage;  // convert to actual voltage from bit reading
  return ADCVoltage;
}

int ADC::readRaw() {
  std::ifstream ifs;  // filestream variable used to read from voltage file
  int rawADC = 0;     // variable used to store direct reading
  ifs.open(ADCVoltageFile.c_str());  // open the voltage file
  if (!(ifs.is_open())) {
    std::cout << "Cannot get the ADC Voltage.\n";
    // throw exception;
  } else {
    ifs >> rawADC;  // read the file voltage (in bits) into the temporary
                    // storage variable
  }
  ifs.close();             // close the file
  ADCRawReading = rawADC;  // put the reading in the class variable
                           // ADCRawReading -- not necessary, but done
  return rawADC;           // return the voltage reading
}
