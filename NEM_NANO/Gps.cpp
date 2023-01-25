/*
  Gps.h - Library for wraping the functions controling the Gps 
  Author - Konstantinos Papageorgiou kp at rei.gr 2022 
*/

#include "Arduino.h"
#include "Gps.h" 
#include <AltSoftSerial.h>
#include <TinyGPS++.h>
#include "Context.h"

Gps::Gps(byte pin){}

void Gps::setup(Context &_context){
  context = &_context;
  gpsPort.begin(9600);
}

void Gps::apply(){
  while (gpsPort.available() > 0)
    gps.encode(gpsPort.read());   

  context->satellites = gps.satellites.value();


    context->speed = gps.speed.mps();
    
    context->latlng[0] = gps.location.lat();
    context->latlng[1] = gps.location.lng();
    
    context->isGPSLocked = context->latlng[0] != 0.0;
    
    if(context->isGPSLocked){
      if(context->GPSLockTime == 0){
        context->GPSLockTime = context->now;
        context->color = 1;
        context->intervals[5] = 200;
      }else{
        if(
            (context->now -context->GPSLockTime) > 10000 &&
            context->TARGET_LAT == 37.9584512 && 
            context->satellites > 5
        ){
          context->TARGET_LAT = context->latlng[0];
          context->TARGET_LNG = context->latlng[1];
          context->color = 2;
        }
      }
      context->intervals[5] = 1003;
      processTarget();
    }
}

void Gps::processTarget(){ 
  context->targets[1] = gps.courseTo(
    context->latlng[0], context->latlng[1], 
    context->TARGET_LAT, context->TARGET_LNG
  );  

  context->targets[2] = gps.distanceBetween(
    context->latlng[0], context->latlng[1], 
    context->TARGET_LAT, context->TARGET_LNG
  );
 
}
