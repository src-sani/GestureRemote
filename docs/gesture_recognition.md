# Gesture Recognition

## Overview

The GestureRemote system uses motion data from the MPU6050 to recognize four wrist gestures:

* LEFT
* RIGHT
* UP
* DOWN

The STM32 processes the sensor data and converts the detected movement into a corresponding command.

## Gesture Mapping

| Gesture | Command | Intended Action |
| ------- | ------- | --------------- |
| LEFT    | `LEFT`  | Previous        |
| RIGHT   | `RIGHT` | Next            |
| UP      | `UP`    | Volume Up       |
| DOWN    | `DOWN`  | Volume Down     |

## Detection Method

The gesture recognition algorithm analyzes changes in the MPU6050 sensor readings.

Instead of relying only on a fixed sensor position, the algorithm compares changes in the sensor values with the previous state.

This allows the system to detect the direction of movement rather than continuously detecting the same position.

## Edge-Based Detection

The recognition logic was refined to detect a gesture when the sensor state changes from one direction to another.

For example, when the sensor is moved continuously in one direction, the corresponding command is generated once instead of repeatedly generating the same command.

This reduces unwanted repeated commands during continuous movement.

## Gesture Testing

The four gestures were tested in the Wokwi simulation:

* LEFT
* RIGHT
* UP
* DOWN

Each recognized gesture was mapped to its corresponding LED and command.

The simulation successfully recognized the required gestures.

## Current Status

**LEFT detection:** ✅ Working

**RIGHT detection:** ✅ Working

**UP detection:** ✅ Working

**DOWN detection:** ✅ Working

**Continuous movement handling:** ✅ Tested

**Physical gesture testing:** 🔄 Pending final hardware integration

