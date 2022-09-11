/*
  Context.h - Library for wraping the functions controling the Context / enviroment information
  Author - Konstantinos Papageorgiou kp at rei.gr 2022  
*/

#ifndef Context_h
#define Context_h

#include "Arduino.h" 

class Context{
  public:
    Context(byte pin);
    void setup();
    void apply();
    void reflectSensor(float value, byte precission);
    void setGPSTarget(double LAT, double LNG);

    // Enviroment values
    //-----------------------
    // GPS related
    boolean isGPSLocked = false;
    unsigned long GPSLockTime = 0;
    double latlng[2] = {0, 0}; // gps position
    double TARGET_LAT = 37.9584512; //Akropolis
    double TARGET_LNG = 23.7502464;

    float targets[5] = {0, 0, 0, 0, 0}; // heading target, target gps degree, target gps distance meters, x distance, y distance

    int satellites = 0;
    double speed=0;
    // Power related
    float voltage = 0;
    byte capacity = 0;
    boolean isLowBattery = false;

    byte color = 0;
    // Invoker variables - execution functions frequencies
    int intervals[6] = {10, 52, 104, 500, 1008, 5000};
    unsigned long now = millis();
    unsigned long timers[8] = {now, now, now, now};

  private:
    byte _pin;
};

#endif
