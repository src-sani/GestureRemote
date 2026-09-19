# Hardware Components

## Main Components

| Component              | Purpose                                                                                        |
| ---------------------- | ---------------------------------------------------------------------------------------------- |
| STM32 Blue Pill        | Main microcontroller that processes sensor data and generates control commands                 |
| MPU6050                | 6-axis IMU used to detect wrist movement and gestures                                          |
| HC-05 Bluetooth Module | Provides wireless communication between the STM32 and laptop                                   |
| Push Button            | Activates gesture detection and provides a reference point for detecting intentional movements |
| Breadboard             | Used for prototyping and connecting the electronic components                                  |
| Jumper Wires           | Used to make electrical connections between the components                                     |
| LEDs                   | Used as visual indicators during testing and debugging                                         |
| ST-Link                | Used to program and debug the STM32 Blue Pill                                                  |

## Project Input

The MPU6050 provides motion data to the STM32. The STM32 processes the sensor data and identifies four gestures:

* LEFT
* RIGHT
* UP
* DOWN

The push button is used to activate gesture detection. This helps distinguish intentional gestures from normal wrist movement.

## Wireless Communication

After a gesture is recognized, the STM32 sends the corresponding command through the Bluetooth module to the connected laptop.

The commands are:

| Gesture | Command     |
| ------- | ----------- |
| LEFT    | Previous    |
| RIGHT   | Next        |
| UP      | Volume Up   |
| DOWN    | Volume Down |

## Testing Indicators

LEDs are used during development to provide visual confirmation of detected or transmitted commands. They are primarily intended for testing and debugging.

## Programming and Debugging

The ST-Link is used to program and debug the STM32 Blue Pill during development and testing.
