# Software Testing

## Overview

Before testing the physical hardware, the command and laptop-control logic was tested using Python programs.

A fake sender was used to generate gesture commands, while a fake receiver was used to receive the commands and perform the corresponding laptop actions.

This allowed the software logic to be tested independently of the STM32, MPU6050, and Bluetooth hardware.

## Testing Setup

Two Python programs were used:

* **Fake Sender**: Sends commands entered through the terminal.
* **Fake Receiver**: Receives the commands and performs the corresponding laptop action.

## Commands Tested

| Command | Laptop Action |
| ------- | ------------- |
| `LEFT`  | Previous      |
| `RIGHT` | Next          |
| `UP`    | Volume Up     |
| `DOWN`  | Volume Down   |

## Testing Process

1. The fake receiver program was started on the laptop.
2. The fake sender program was started separately.
3. Commands such as `RIGHT`, `LEFT`, `UP`, and `DOWN` were entered through the sender.
4. The receiver accepted the commands.
5. The corresponding laptop actions were performed.

## Test Result

All four commands were successfully tested.

The software-only test confirmed that the command format, receiving logic, and laptop-control functions were working before integrating the hardware.

## Files

The testing programs are available in:

`software/testing/`

The files include:

* `fake_sender.py`
* `fake_receiver.py`

## Status

**Command generation:** ✅ Tested

**Command receiving:** ✅ Tested

**Laptop control:** ✅ Tested

**Hardware integration:** 🔄 Tested separately in later stages
