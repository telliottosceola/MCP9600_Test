#ifndef MCP9600_H
#define MCP9600_H

#include <HardwareSerial.h>
#include <Wire.h>


class ThermoCouple{
public:
  bool init(int address);
  int discover();
  float readTemp();
  int error = 256;
  bool fahrenheit = true;
private:
  int address = 0x64;
  int data[2];
  int status;
  unsigned long readTimeout = 300;
  unsigned long startTime;
  int i2cClockSpeed = 75000;
  bool temrmo_set();
  bool device_set();
};

#endif
