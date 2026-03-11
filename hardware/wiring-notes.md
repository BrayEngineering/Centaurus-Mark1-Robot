# Centaurus (Mark I) – Hardware Wiring Notes

## Overview

This document describes how the electronic components of Centaurus (Mark I) are connected to the Arduino Uno and motor driver.

The system integrates:

- Arduino Uno microcontroller
- TB6612 dual motor driver
- ultrasonic distance sensor
- IR receiver
- shift register for LED control
- DC motors

The Arduino acts as the central controller, receiving sensor input and sending control signals to the motors and LEDs.



## Motor Driver Wiring

The robot uses a **TB6612 dual H-bridge motor driver** to control two DC motors.

Motor driver control pins connected to the Arduino:

| Motor Driver Pin | Arduino Pin |
|-----------------|-------------|
| AN1 | 12 |
| AN2 | 4 |
| BN1 | 7 |
| BN2 | 8 |
| PWMA | 5 |
| PWMB | 6 |
| STBY | 9 |

The driver allows the Arduino to control motor direction and speed using PWM signals.



## Ultrasonic Sensor Wiring

An ultrasonic distance sensor is used for obstacle detection.

Connections:

| Sensor Pin | Arduino Pin |
|-----------|-------------|
| Trigger | 3 |
| Echo | A2 |
| VCC | 5V |
| GND | GND |

The sensor measures the distance to objects in front of the robot and provides data used for autonomous navigation.



## IR Receiver Wiring

The IR receiver allows manual control of the robot using a remote.

Connections:

| IR Receiver Pin | Arduino Pin |
|----------------|-------------|
| Signal | A0 |
| VCC | 5V |
| GND | GND |

The receiver decodes commands from the remote which are interpreted by the Arduino control program.



## LED Shift Register Wiring

A shift register is used to control multiple LEDs with a limited number of Arduino pins.

Connections:

| Shift Register Pin | Arduino Pin |
|------------------|-------------|
| Data | A3 |
| Clock | 13 |
| Latch | 2 |

The shift register allows LED patterns to be displayed while minimizing Arduino pin usage.



## Motor Connections

Two DC motors are connected to the TB6612 motor driver.

- Motor A controls the left wheel
- Motor B controls the right wheel

By controlling each motor independently, the robot can:

- move forward
- move backward
- turn left
- turn right

This steering method is known as **differential drive**.



## Power System

The robot is powered by a battery mounted inside the chassis.

Power distribution:

- Battery → motor driver
- Arduino receives regulated power
- Sensors and LEDs are powered from the Arduino 5V output

All components share a common ground connection.



## Fabrication Tools Used

The chassis and internal mounting structure were built using basic fabrication tools.

Tools used:

- Jig saw
- Wood sander
- Wood carving tools
- Drill
- Soldering iron

Materials used:

- Wood boards
- Screws
- Velcro mounting strips
- Duct tape



## Notes

The internal wiring layout was adjusted several times during development to improve reliability and simplify maintenance.

Components were mounted using screws and Velcro to allow easy access for testing and future modifications.
