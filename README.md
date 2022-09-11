# NEM NANO 

NEM GPS FLYSKY DISTANCE, Voltage, speed sensor on Arduino nano

The component, derives and transmits the distance from home, the external voltage, the gps coordinates, the gps satellites, the speed 10cm/sec, to the flysky remote controller (flysky FS-I6X) screen, using an Arduino nano. Built using a custom pcb and software designed, for http://nem.gr  Github repo: https://github.com/meltoner/NEM_NANO

- https://www.youtube.com/watch?v=HKdX1mCnNCI

## Software Features :

- Software utilities a GPS, remote control on an arduino nano
- Sensors and actuators are all in classes
- Implements five tasks execution frequencies
- Auto derives home after 10 seconds since first lock, and after seeing at least 6 satellites
- Derives distance and degrees from a target gps LAT LOT
- Transmits distance, speed, voltage, gps coordinates using two number per coordinate
- Led indicator low periodicity no gps lock, high periodicity gps lock
- doesn't occupy a serial port to transmit telemetry

## Hardware

Sensors :

- Gps : Ublox M8N with compass
- Voltage sensor 0-25v MH-electronic
- Receiver : flysky F9-ia10b

Main components : 
- Transmitter : flysky FS-I6X
- Receiver : [flysky FS-1A10B](https://www.flysky-cn.com/ia10b-canshu)
- Arduino nano

Other: 

- LED
- 3 Pin Female connectors, ribbon cable, conectors, board, box, battery, etc
