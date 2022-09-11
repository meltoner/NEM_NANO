/*
  Telemetry.h - Library for wraping the functions controling the remote control i/o
  Author - Konstantinos Papageorgiou kp at rei.gr 2022 
  https://github.com/adis1313/iBUSTelemetry-Arduino
*/

#ifndef Telemetry_h
#define Telemetry_h

#include "Arduino.h"
#include "Context.h"
#include <iBUSTelemetry.h>

class Telemetry{
  public:
    Telemetry(byte pin);
    void setup(Context &_context);
    void apply();
    void run();
    String double2string(double n, int ndec);
    int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue);
    Context *context;        
  private: 
    iBUSTelemetry telem = iBUSTelemetry(10);
};

#endif
