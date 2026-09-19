# Bluetooth Testing

## Overview

The HC-05 Bluetooth module was tested with the STM32 Blue Pill to verify wireless communication between the microcontroller and a laptop.

The STM32 was programmed to transmit gesture commands through the Bluetooth module.

## Hardware Used

* STM32 Blue Pill
* HC-05 Bluetooth Module
* LEDs for testing
* ST-Link
* Laptop

## Bluetooth Communication

The STM32 communicated with the HC-05 using serial communication.

The communication speed was configured to:

`9600 baud`

The commands tested were:

* `RIGHT`
* `LEFT`
* `UP`
* `DOWN`

## Testing Method

A Bluetooth test program was used to automatically send the four commands from the STM32.

For each transmitted command, the corresponding LED was also blinked on the STM32. This provided a visual indication that the command was being transmitted.

The commands were received by the laptop through the HC-05 Bluetooth connection.

## Laptop Receiver

A Python receiver program was used on the laptop to receive and process the Bluetooth commands.

The received commands were mapped to laptop actions:

| Command | Laptop Action |
| ------- | ------------- |
| `LEFT`  | Previous      |
| `RIGHT` | Next          |
| `UP`    | Volume Up     |
| `DOWN`  | Volume Down   |

PowerPoint slide navigation was tested using the LEFT and RIGHT commands.

Laptop volume control was tested using the UP and DOWN commands.

## Test Result

The Bluetooth communication was successfully tested.

The STM32 transmitted the commands through the HC-05, and the laptop successfully received and processed them.

The Bluetooth test confirmed that the wireless communication and laptop control portions of the system were working.

## Files

The Bluetooth test firmware is available in:

`firmware/bluetooth/`

The laptop receiver is available in:

`software/receiver/`

## Status

**STM32 → HC-05 communication:** ✅ Tested

**HC-05 → Laptop communication:** ✅ Tested

**Command transmission:** ✅ Working

**Laptop control:** ✅ Tested

**Full MPU6050 + Button + Bluetooth integration:** 🔄 In Progress
