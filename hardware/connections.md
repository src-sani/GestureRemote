# Hardware Connections

## 1. MPU6050 + STM32 Blue Pill (Wokwi)

The MPU6050 was connected to the STM32 Blue Pill in Wokwi using the I²C interface.

| MPU6050 | STM32 Blue Pill |
| ------- | --------------- |
| VCC     | 3.3V            |
| GND     | GND             |
| SDA     | STM32 I²C SDA   |
| SCL     | STM32 I²C SCL   |

The MPU6050 was configured with the I²C address:

```text
0x68
```

The Wokwi simulation was used to test motion sensing and recognize:

* UP
* DOWN
* LEFT
* RIGHT

The corresponding LEDs were connected to:

| Gesture | STM32 Pin |
| ------- | --------- |
| UP      | PA0       |
| DOWN    | PA1       |
| LEFT    | PA2       |
| RIGHT   | PA3       |

The complete Wokwi project is available in:

```text
firmware/mpu6050/
```

---

## 2. STM32 + HC-05 Bluetooth Module

The HC-05 was physically tested with the STM32 Blue Pill.

The module was powered using the available power connections, and serial communication was used to transmit commands from the STM32 to the laptop.

The serial communication was configured at:

```text
9600 baud
```

The commands tested were:

```text
RIGHT
LEFT
UP
DOWN
```

The STM32 Bluetooth test code also blinked the corresponding LED whenever a command was transmitted.

### HC-05 connections used during testing

| HC-05 Pin | Connection      |
| --------- | --------------- |
| 5V        | 5V supply       |
| GND       | GND             |
| TX        | STM32 serial RX |
| RX        | STM32 serial TX |

The HC-05 transmitted the commands wirelessly to the laptop, where they were received and processed by the Python receiver.

The Bluetooth test code is available in:

```text
firmware/bluetooth/
```

## 3. Communication Flow

```text
Wokwi:
MPU6050
   ↓
STM32 Blue Pill
   ↓
Gesture Detection
   ↓
LED indication

Physical Bluetooth Test:
STM32 Blue Pill
   ↓
HC-05
   ↓
Laptop
   ↓
Python Receiver
   ↓
Laptop Action
```

> **Note:** These connections document the configurations used during the development and testing stages. The final integrated hardware connections will be added after the complete prototype is assembled and tested.
