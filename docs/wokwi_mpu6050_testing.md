# MPU6050 Testing

## Overview

The MPU6050 was tested with the STM32 Blue Pill using the Wokwi simulator before moving to physical hardware testing.

The purpose of this stage was to verify that the STM32 could communicate with the MPU6050, read motion data, and recognize the required wrist gestures.

## Hardware Used

* STM32 Blue Pill
* MPU6050 6-axis IMU
* LEDs for gesture indication

## Communication

The MPU6050 communicates with the STM32 using the **I²C protocol**.

The MPU6050 was configured with the I²C address:

`0x68`

The project was implemented using the Arduino framework and `Wire.h` library.

## Gesture Recognition

Four gestures were implemented:

| Gesture | Command | LED |
| ------- | ------- | --- |
| LEFT    | `LEFT`  | PA2 |
| RIGHT   | `RIGHT` | PA3 |
| UP      | `UP`    | PA0 |
| DOWN    | `DOWN`  | PA1 |

The STM32 reads the motion data from the MPU6050 and analyzes changes in the sensor values to identify the corresponding gesture.

The recognition logic was refined to detect changes in movement rather than relying only on fixed sensor positions. This helped prevent continuous movement from repeatedly generating the same command.

## Testing Process

The MPU6050 and STM32 were first connected in Wokwi.

The simulation was then used to:

1. Initialize the MPU6050.
2. Verify communication between the MPU6050 and STM32.
3. Read motion data from the sensor.
4. Process the changes in sensor values.
5. Detect LEFT, RIGHT, UP, and DOWN gestures.
6. Blink the corresponding LED when a gesture was detected.

## Test Result

The Wokwi simulation successfully detected all four required gestures.

The corresponding LEDs were used to visually confirm the detected gesture.

The gesture recognition stage was successfully completed in simulation.

## Wokwi Project Files

The complete Wokwi project is available in:

`firmware/mpu6050/`

It contains:

* `diagram.json`
* `Libraries.txt`
* `Wokwi Project.txt`
* `Wokwi STM32 Bluetooth.ino`

## Status

**MPU6050 sensor reading:** ✅ Tested

**Gesture recognition:** ✅ Tested

**LEFT / RIGHT / UP / DOWN detection:** ✅ Working

**LED indication:** ✅ Tested

**Physical MPU6050 integration:** 🔄 Pending final hardware integration
