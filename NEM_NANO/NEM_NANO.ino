// @author : Konstantinos Papageorgiou - 2022 - kp at rei.gr
// @repo: https://github.com/meltoner/NEM_NANO
//
// # NEM NANO DISTANCE
// 
// NEM GPS FLYSKY GPS DISTANCE, Voltage SENSOR on Arduino nano
// 
// Derives and transmits the distance from home, voltage, gps coordinates, gps sattelite, speed to the flysky remote controller screen using an arduino nano 
// 
// ## Software Features :
// 
// - Software utilities a GPS, remote control on an arduino nano
// - Sensors and actuators are all in classes
// - Implements five tasks execution frequencies
// - Auto derives home after 10 seconds since first lock, and after seeing at least 6 satellites
// - Derives distance and degrees from a target gps LAT LOT
// - Transmits distance, speed, voltage, gps coordinates using two number per coordinate
// - Led indicator low periodicity no gps lock, high periodicity gps lock
// - doesn't occupy a serial port to transmit telemetry
// 
// ## Hardware
// 
// Sensors :
// 
// - Gps : Ublox M8N with compass
// - Voltage sensor 0-25v MH-electronic
// - Receiver : flysky F9-ia10b
// 
// Main components : 
// - Transmitter : flysky FS-I6X
// - Receiver : [flysky FS-1A10B](https://www.flysky-cn.com/ia10b-canshu)
// - Arduino nano
// 
// Other: 
// 
// - LED
// - 3 Pin Female connectors, ribbon cable, conectors, board, box, battery, etc


#include "Context.h"
#include "Invoker.h"
#include "Blink.h"
#include "Gps.h" 
#include "Telemetry.h"
#include "Battery.h"

Context context(0);
Invoker invoker(0);
Blink blink(0);
Gps gps(0);
Telemetry telemetry(0);
Battery battery(0);

//-----------------------------------------

void setup() {
  context.setup();
  blink.setup(context);
  telemetry.setup(context);
  gps.setup(context);
  battery.setup(context);
  invoker.setup(context);
}

void apply_very_fast_invoker(){
}

void apply_fast_invoker(){
}

void apply_invoker(){
  gps.apply();
}

void apply_slow_invoker(){
  telemetry.apply();
  context.apply(); // every 0.5 second printout / log enviromental variables  
}

void apply_slower_invoker(){
  battery.apply();
}

void apply_heartbeat_invoker(){
  blink.apply();
}

void run_invoker(int i){
    switch(i){
      case 0: apply_very_fast_invoker(); break;
      case 1: apply_fast_invoker(); break;
      case 2: apply_invoker(); break;
      case 3: apply_slow_invoker(); break;
      case 4: apply_slower_invoker(); break;
      case 5: apply_heartbeat_invoker(); break;
      case 100: break;
    }
}

void loop(){
  telemetry.run(); // must be first
  int actionIndex = invoker.apply();
  while(actionIndex != 100){
    run_invoker(actionIndex);
    actionIndex = invoker.apply();
  }

}
