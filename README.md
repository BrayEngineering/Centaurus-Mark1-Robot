# The Centaurus (Mark 1)

Centaurus (Mark 1) is an Arduino-based robotics platform designed for maneuverability and remote-controlled movement using DC motors and sensors.

---

## Features

- IR remote control driving  
- Obstacle detection using ultrasonic sensor  
- LED light patterns  
- Randomized obstacle-avoidance mode  

---

## Extended Description

Centaurus (Mark 1) is a custom-built Arduino robotics platform created to demonstrate motor control, sensor integration, and remote-controlled navigation. The robot uses DC motors connected to an H-bridge motor driver to provide movement and maneuverability.

Movement is primarily controlled using an infrared (IR) remote. The remote allows the operator to command the robot to move forward, reverse, and turn left or right. This manual control mode allows the robot to function like a small remote-controlled vehicle while also acting as a platform for experimenting with embedded motor control.

In addition to manual control, the robot incorporates an ultrasonic distance sensor that detects nearby obstacles. When obstacle-avoidance mode is active, the robot scans its surroundings and randomly selects turning directions when an obstacle is detected. This creates a simple autonomous behavior similar to early robotics navigation systems.

Centaurus also includes a custom LED lighting system driven by a shift register. The LEDs display animated patterns that change depending on the robot's movement state, creating visual feedback during actions such as forward motion, reversing, or turning.

---

## Demo Video #1

<a href="https://www.tiktok.com/@the_centaurus/video/7085929355746102570">
  <img src="https://github.com/user-attachments/assets/552bac9e-598d-45a5-9825-6131898b9100" width="350">
</a>

## Demo Video #2

<a href="https://www.tiktok.com/@the_centaurus/video/7086537984648105262">
 <img width="350" height="350" alt="image" src="https://github.com/user-attachments/assets/4e36fa52-c165-46f4-a453-0c61a9b9c9dc" >
</a>


---

## Final Robot

<img src="https://github.com/user-attachments/assets/0bc2d1e3-ac93-456b-9804-c14b1013c71f" width="700">

---

## Build Process

The chassis for Centaurus (Mark 1) was constructed from wood rather than 3D-printed parts. At the time of the build, a 3D printer was not available, so the frame was designed and assembled using wooden boards and basic tools.

The wooden structure provides a durable mounting platform for the Arduino Uno, motor driver, sensors, and battery while also leaving enough internal space for wiring and LED installation. Using wood allowed the robot to be built using readily available materials while still maintaining structural stability for the motors and electronics.

<img src="https://github.com/user-attachments/assets/a4a6e048-7664-4c7a-956b-738e04c98a68" width="500">

---

## Hardware Used

- Arduino Uno  
- Ultrasonic sensor  
- DC motors  
- H-bridge motor driver  
- IR remote receiver  
- LEDs and shift register  
- 9V battery  

---

## Additional Images

<img src="https://github.com/user-attachments/assets/4b01fbdc-61c3-486a-b2df-09675200f135" width="500">

<img src="https://github.com/user-attachments/assets/0e93bcde-2218-4566-99e5-8dd7fb4e428e" width="500">

<img src="https://github.com/user-attachments/assets/1e8dcba9-1620-42c7-984e-c3509961f7c8" width="500">

<img src="https://github.com/user-attachments/assets/1229a65f-077f-43f5-ba20-965ca7e28d40" width="500">

---

## Code Overview

The main Arduino program for Centaurus (Mark 1) is located in:

`code/robot-control.ino`

This file controls the complete robotic system including:

- IR remote driving commands
- DC motor control using the TB6612 motor driver
- Ultrasonic obstacle detection
- LED lighting patterns through a shift register
- Autonomous obstacle-avoidance mode

The program integrates motor control, sensor input, and LED feedback to allow both manual remote driving and basic autonomous navigation.

Libraries used:

- `SparkFun_TB6612.h`
- `IRremote.h`



## Project Structure

```
centaurus-mark1-robot
│
├── code
│   └── robot-control.ino
│       Arduino program controlling motors, sensors, and LEDs
│
├── docs
│   └── design-report.md
│       Design explanation and system notes
│
├── hardware
│   └── wiring-notes.md
│       Wiring layout and hardware connections
│
└── README.md
    Main project overview and documentation
```

---

## Future Improvements

- Add fully autonomous navigation  
- Improve chassis durability  
- Upgrade battery system  
- Add Bluetooth or wireless control
