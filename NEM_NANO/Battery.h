/*
  Battery.h - Library for warping the functions relevant to the Battery power levels
  Author - Konstantinos Papageorgiou kp at rei.gr 2022 
*/

#ifndef Battery_h
#define Battery_h

#include "Arduino.h" 
#include "Context.h"

class Battery{
  public:
    Battery(byte pin);
    void setup(Context &_context);
    void apply();
    float measureVoltage();
  private:

    byte cells = 1;
    float minV = 3.54;
    float maxV = 4.2;
    Context *context;
};

#endif

// cell min   max
// 1    3.54  4.2
// 2    7.08  8.4
// 3    10.62 12.6
// 4    14.16 16.8
// 5    17.7  21
// 6    21.24 25.2
// 7    24.78 29.4
// 8    28.32 33.6
