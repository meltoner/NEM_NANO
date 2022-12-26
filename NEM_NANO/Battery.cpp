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
  measureVoltage();
  // battery cell detection based on single cell min (3.54), max (4.2) multiples
  for(cells = 1;cells < 6;cells++)
    if((cells * minV) > context->voltage ){
      cells--;
      break;
    }
}

float Battery::measureVoltage(){
  context->voltage =  analogRead(0) / 40.92;
  context->voltage = context->voltage + 0.5;
  return context->voltage;
}

void Battery::apply(){
  measureVoltage();
  // derive how close we are to the min voltage based on the number of cell
  context->capacity = (byte)( ((context->voltage - (cells * minV)) / (context->voltage - (cells * maxV))) * 100 ); 
  context->isLowBattery = context->voltage < (cells * minV);
}
