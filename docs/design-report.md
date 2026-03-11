# Centaurus (Mark I) – Design Report

## 1. Project Objective

The goal of Centaurus (Mark I) was to design and build a small Arduino-based robotic platform capable of both manual remote control and basic autonomous navigation.

The project was created to explore core robotics concepts including:

- Embedded microcontroller programming
- DC motor control
- Sensor-based navigation
- Hardware integration
- Mechanical prototyping

The robot serves as a learning platform for experimenting with simple robotic behaviors such as obstacle avoidance and remote-controlled maneuverability.


## 2. System Overview

Centaurus (Mark I) consists of four main subsystems:

### Mechanical System
The physical chassis and structure of the robot.

### Control System
An Arduino Uno microcontroller responsible for running the robot’s control logic.

### Motion System
DC motors controlled by a dual H-bridge motor driver.

### Sensor and Input System
Sensors and remote commands used to control and guide the robot.

The system supports two operating modes:

- Manual driving using an IR remote
- Autonomous obstacle-avoidance mode


## 3. Mechanical Design

The chassis of Centaurus was constructed using wood rather than 3D-printed parts. At the time of development a 3D printer was not available, so the frame was designed and built using wooden boards and basic fabrication tools.

This approach provided several advantages:

- inexpensive materials
- easy modifications during prototyping
- strong mounting points for motors and electronics
- enough internal space for wiring and battery placement

The motors were mounted to the base of the chassis and connected to drive wheels, allowing differential steering by controlling the left and right motors independently.


## 4. Electronics Architecture

The electronics system is centered around an Arduino Uno microcontroller which manages both input signals and output control.

Major electronic components include:

| Component | Purpose |
|--------|--------|
| Arduino Uno | Main controller |
| TB6612 Motor Driver | Controls motor direction and speed |
| Ultrasonic Sensor | Measures obstacle distance |
| IR Receiver | Receives remote control commands |
| Shift Register | Controls LED lighting patterns |
| LEDs | Visual feedback for robot behavior |
| DC Motors | Drive robot wheels |
| Battery | Power source |

The Arduino processes signals from sensors and the IR remote, then sends commands to the motor driver and LED system.


## 5. Control Logic

The robot is controlled by the Arduino program located in:

`code/robot-control.ino`

The program integrates sensor input, motor control, and LED feedback.

### Manual Mode

Using the IR remote, the robot can:

- Move forward
- Move backward
- Turn left
- Turn right
- Stop

These commands directly control the motors through the TB6612 motor driver.


### Autonomous Mode

When autonomous mode is activated, the ultrasonic sensor continuously measures the distance in front of the robot.

Based on the measured distance, the robot performs different behaviors:

| Distance | Behavior |
|-------|---------|
| Far distance | Move forward at full speed |
| Medium distance | Reduce speed |
| Close obstacle | Reverse |
| Intermediate distance | Randomly turn left or right |

Random turning allows the robot to escape obstacles and continue navigating.


## 6. LED Feedback System

A shift register is used to control multiple LEDs mounted on the robot.

These LEDs provide visual feedback for different states:

- Forward motion
- Reverse motion
- Turning behavior
- System activity

LED patterns were implemented in software to help visualize the robot’s behavior during operation.


## 7. Fabrication Tools and Materials

The following tools and materials were used to construct the robot chassis and assemble the electronics.

### Tools

- Jig saw
- Wood sander
- Wood carving tools
- Drill
- Soldering iron

### Materials

- Wood boards
- Screws
- Velcro mounting strips
- Duct tape


## 8. Development Challenges

Several challenges were encountered during development.

### Mechanical layout
Fitting motors, electronics, wiring, and the battery within the wooden chassis required multiple layout adjustments.

### Sensor tuning
The ultrasonic sensor thresholds had to be adjusted to achieve reliable obstacle detection.

### Electrical integration
Managing multiple electronic components required careful wiring and debugging.


## 9. Future Improvements

Future versions of Centaurus could include:

- Improved chassis design using 3D printing
- Rechargeable battery system
- Wireless control via Bluetooth or Wi-Fi
- Camera-based vision
- More advanced autonomous navigation algorithms

These improvements would expand the robot’s capabilities and provide a stronger robotics development platform.
