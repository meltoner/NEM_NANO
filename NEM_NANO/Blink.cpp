/*
  Blink.h - Library for wraping the functions controling the Return to Blink 
  Author - Konstantinos Papageorgiou kp at rei.gr 2022
*/

#include "Arduino.h"
#include "Blink.h" 
#include "Context.h"

Blink::Blink(byte pin){}

void Blink::setup(Context &_context){
  context = &_context;
  pinMode(2, OUTPUT);
  apply();
}

void Blink::apply(){
  digitalWrite(2, !digitalRead(2));
}
