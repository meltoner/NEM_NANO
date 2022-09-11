# NEM NANO 

NEM GPS FLYSKY DISTANCE, Voltage, speed sensor telemetry on Arduino nano

The component, derives and transmits telemetry information such as distance from home, external voltage, GPS coordinates, GPS satellites, speed 10cm/sec, to the flysky FS-I6X remote controller, using an Arduino nano. Built using a custom PCB and software developed, with http://nem.gr

## Video showcase

- https://www.youtube.com/watch?v=HKdX1mCnNCI

## Software Features :

- Software utilises a GPS, a voltage sensor and remote controller actuator, using an Arduino nano
- Sensors and actuators are all implemented using classes
- Implements five execution frequencies
- Auto derives home after 10 seconds since the gps lock and after locking with at least 6 satellites
- Transmits meters distance from home
- Transmits speed in 10cm/second
- Transmits the external Voltage
- Transmits the GPS coordinates using two numbers (four digit) per coordinate
- Led indicator having low periodicity when no gps is locked, and with high periodicity when gps is locked.
- Implementation does not occupy a serial port to transmit telemetry information

## Hardware

- Arduino nano
- Gps : Ublox M8N with compass
- Voltage sensor 0-25v MH-electronic
- Transmitter : flysky FS-I6X
- Receiver : [flysky FS-1A10B](https://www.flysky-cn.com/ia10b-canshu)
- LED and resistance
- 3 Pin Female connectors, ribbon cable, conectors, custom board, battery

## Connectivity

- https://github.com/meltoner/NEM_NANO/blob/main/supportive/nem_nano_connections.pdf

## Images

- https://github.com/meltoner/NEM_NANO/tree/main/media

## PCB board 

- https://github.com/meltoner/NEM_NANO/tree/main/pcb_and_box
