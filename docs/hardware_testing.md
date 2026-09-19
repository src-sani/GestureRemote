# Hardware Testing

## Overview

Physical hardware testing was carried out to verify the STM32 Blue Pill and HC-05 Bluetooth module before completing the full wearable prototype.

The testing focused on programming the STM32, transmitting commands through Bluetooth, and verifying the resulting laptop actions.

## Hardware Tested

* STM32 Blue Pill
* HC-05 Bluetooth Module
* LEDs
* ST-Link
* Breadboard
* Jumper Wires
* Laptop

## STM32 Testing

The STM32 Blue Pill was programmed using the ST-Link.

Basic board operation was verified before proceeding with Bluetooth testing.

## Bluetooth Hardware Test

The HC-05 Bluetooth module was connected to the STM32 and used for wireless serial communication.

The STM32 transmitted the following commands:

* `RIGHT`
* `LEFT`
* `UP`
* `DOWN`

The Bluetooth communication was configured at **9600 baud**.

During the test, the corresponding LED was blinked whenever a command was transmitted. This provided a local visual indication of the transmitted command.

## Laptop Testing

The HC-05 was connected wirelessly to the laptop.

The Python receiver program received the transmitted commands and converted them into laptop actions.

The following actions were successfully tested:

| Command | Result                                 |
| ------- | -------------------------------------- |
| `RIGHT` | PowerPoint moved to the next slide     |
| `LEFT`  | PowerPoint moved to the previous slide |
| `UP`    | Laptop volume increased                |
| `DOWN`  | Laptop volume decreased                |

## Test Result

The physical STM32 and Bluetooth communication was successfully verified.

The test confirmed that:

* The STM32 could transmit commands.
* The HC-05 could communicate with the laptop.
* The Python receiver could process the commands.
* The laptop could perform the intended actions.

## Current Status

**STM32 hardware:** ✅ Tested

**HC-05 Bluetooth:** ✅ Tested

**Laptop control:** ✅ Tested

**MPU6050 physical integration:** 🔄 Pending

**Activation button integration:** 🔄 Pending

**Complete wearable prototype:** 🔄 In Progress
