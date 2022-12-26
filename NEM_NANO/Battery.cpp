/*
  Battery.h - Library for warping the functions controlling the Battery power levels
  Author - Konstantinos Papageorgiou kp at rei.gr 2022 
*/

#include "Arduino.h"
#include "Battery.h" 
#include "Context.h"

Battery::Battery(byte pin){}

void Battery::setup(Context &_context){
  context = &_context;
  apply();
}

void Battery::apply(){
  context->voltage =  analogRead(A7) / 40.92; 
  // abstract to % based on range 6v to 7.4v    
  context->capacity = (byte)(context->voltage < 6 ? 0:(context->voltage - 6) * 71.428);
  if(context->capacity > 100)
    context->capacity = 100;

  context->isLowBattery = context->capacity < 40;
  //if(context->isLowBattery)
  //  context->intervals[5] = 60;

}