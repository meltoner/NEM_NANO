/*
  Blink.h - Library for wraping the functions controling the Blink 
  Author - Konstantinos Papageorgiou kp at rei.gr 2022
*/

#ifndef Blink_h
#define Blink_h

#include "Arduino.h" 
#include "Context.h"

class Blink{
  public:
    Blink(byte pin);
    void setup(Context &_context);
    void apply();
  private:
    Context *context;
};

#endif