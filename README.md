# NEM NANO 

NEM GPS FLYSKY DISTANCE, Voltage, speed sensor on Arduino nano

The component, derives and transmits the distance from home, the external voltage, the gps coordinates, the gps satellites, the speed 10cm/sec, to the flysky remote controller (flysky FS-I6X) screen, using an Arduino nano. Built using a custom pcb and software designed, for http://nem.gr by Konstantinos L. Papageorgiou.

## Video showcase

- https://www.youtube.com/watch?v=HKdX1mCnNCI

## Software Features :

- Software utilities a GPS, remote control on an arduino nano
- Sensors and actuators are all in classes
- Implements five tasks execution frequencies
- Auto derives home after 10 seconds since first gps lock and after locking with at least 6 satellites
- Transmits distance from home
- Transmits speed in 10cm/secon
- Transmits External Voltage,
- Transmits gps coordinates using two numbers per coordinate
- Led indicator low periodicity no gps lock, high periodicity gps lock
- Does not occupy a serial port to transmit telemetry data

## Hardware

Sensors :

- Gps : Ublox M8N with compass
- Voltage sensor 0-25v MH-electronic
- Receiver : flysky F9-ia10b

- Transmitter : flysky FS-I6X
- Receiver : [flysky FS-1A10B](https://www.flysky-cn.com/ia10b-canshu)
- Arduino nano

- LED and resistance
- 3 Pin Female connectors, ribbon cable, conectors, board, box, battery, etc

## Connectivity

- https://github.com/meltoner/NEM_NANO/blob/main/supportive/nem_nano_connections.pdf

## Images

- https://github.com/meltoner/NEM_NANO/tree/main/media

## PCB board 

- https://github.com/meltoner/NEM_NANO/tree/main/pcb_and_box
