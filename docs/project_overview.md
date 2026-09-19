# Wearable Gesture Remote

## Overview

Wearable Gesture Remote is a gesture-based control system designed to allow users to control a laptop through simple wrist movements.

The system uses an **STM32 Blue Pill** as the main microcontroller and an **MPU6050 6-axis IMU** to detect wrist movements. The detected gestures are converted into commands such as `LEFT`, `RIGHT`, `UP`, and `DOWN`.

An **HC-05 Bluetooth module** is used to transmit commands wirelessly from the STM32 to a laptop, where a Python receiver interprets the commands and performs the corresponding action.

## Gesture Commands

| Gesture | Command | Intended Action |
| ------- | ------- | --------------- |
| LEFT    | `LEFT`  | Previous        |
| RIGHT   | `RIGHT` | Next            |
| UP      | `UP`    | Volume Up       |
| DOWN    | `DOWN`  | Volume Down     |

## System Concept

```text
Wrist Movement
      ↓
   MPU6050
      ↓
 STM32 Blue Pill
      ↓
Gesture Recognition
      ↓
LEFT / RIGHT / UP / DOWN
      ↓
    HC-05
      ↓
    Laptop
      ↓
 Python Receiver
      ↓
Laptop Control
```

## Development Progress

The project has been developed and tested in multiple stages.

### Software Command Testing

Before using physical hardware, a Python-based fake sender and fake receiver were used to test the command and laptop-control logic.

### MPU6050 Simulation

The STM32 Blue Pill and MPU6050 were tested in Wokwi. The simulation was used to read motion data, recognize the four gestures, and provide LED indications for the detected commands.

### Bluetooth Hardware Testing

The STM32 Blue Pill was later tested with an HC-05 Bluetooth module. The STM32 transmitted the four commands wirelessly to the laptop, where the Python receiver received and processed them.

### Current Stage

The MPU6050 gesture-recognition system has been tested in simulation, and Bluetooth communication has been tested using physical hardware.

The complete physical integration of the MPU6050, activation push button, STM32, and Bluetooth module is the next development stage.
