// @author : Konstantinos Papageorgiou - 2022 - kp at rei.gr
// @repo: https://github.com/meltoner/NEM_NANO
//
//  # NEM NANO 
//  
//  NEM GPS FLYSKY DISTANCE, Voltage, speed sensor on Arduino nano
//  
//  The component, derives and transmits the distance from home, the external voltage, the gps coordinates, the gps satellites, the speed 10cm/sec, to the flysky //  remote controller (flysky FS-I6X) screen, using an Arduino nano. Built using a custom pcb and software designed, for http://nem.gr by Konstantinos L. Papageorgiou.
//  
//  ## Video showcase
//  
//  - https://www.youtube.com/watch?v=HKdX1mCnNCI
//  
//  ## Software Features :
//  
//  - Software utilities a GPS, remote control on an arduino nano
//  - Sensors and actuators are all in classes
//  - Implements five tasks execution frequencies
//  - Auto derives home after 10 seconds since first lock, and after seeing at least 6 satellites
//  - Derives distance and degrees from a target gps LAT LOT
//  - Transmits distance from home
//  - Transmits speed in 10cm/secon
//  - Transmits External Voltage,
//  - Transmits gps coordinates using two numbers per coordinate
//  - Led indicator low periodicity no gps lock, high periodicity gps lock
//  - Does not occupy a serial port to transmit telemetry data
//  
//  ## Hardware
//  
//  Sensors :
//  
//  - Gps : Ublox M8N with compass
//  - Voltage sensor 0-25v MH-electronic
//  - Receiver : flysky F9-ia10b
//  
//  - Transmitter : flysky FS-I6X
//  - Receiver : [flysky FS-1A10B](https://www.flysky-cn.com/ia10b-canshu)
//  - Arduino nano
//  
//  - LED
//  - 3 Pin Female connectors, ribbon cable, conectors, board, box, battery, etc
//  
//  ## Connectivity
//  
//  - https://github.com/meltoner/NEM_NANO/blob/main/supportive/nem_nano_connections.pdf
//  
//  ## Images
//  
//  - https://github.com/meltoner/NEM_NANO/tree/main/media
//  
//  ## PCB board 
//  
//  - https://github.com/meltoner/NEM_NANO/tree/main/pcb_and_box
//  


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
