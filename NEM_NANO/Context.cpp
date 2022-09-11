/*
  Context.h - Library for wraping the functions controling the Enviroment context
  Author - Konstantinos Papageorgiou kp at rei.gr 2022
*/

#include "Arduino.h"
#include "Context.h"

Context::Context(byte pin){  
  _pin = pin;
}

void Context::setup(){
    Serial.begin(9600);
}

void Context::reflectSensor(float value, byte precission){
  Serial.print(value, value == 0?0:precission);
  Serial.print(" ");
}

void Context::apply(){ // takes 4% of memory

  reflectSensor(capacity, 1); 
  reflectSensor(voltage, 2); 

    for(int i = 0; i < 2; i++)
      reflectSensor(latlng[i], 6); // current gps

    for(int i = 1; i < 3; i++)
      reflectSensor(targets[i], 1); // Target heading, GPS return to home target heading, Gps return to home target distance in meters

  Serial.println(F("")); 
}

void Context::setGPSTarget(double LAT, double LNG){
  TARGET_LAT = LAT;
  TARGET_LNG = LNG;
}
