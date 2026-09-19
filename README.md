# 🎮 GestureRemote

### Wearable Gesture-Based Remote Control using STM32

> A wearable control system that uses wrist movements to send commands wirelessly to a laptop.

---

## 📖 About the Project

**GestureRemote** is a wearable gesture-based remote control system built around an **STM32 Blue Pill** and an **MPU6050 6-axis IMU**.

Instead of relying on traditional buttons or physical remote controls, the system interprets simple wrist movements as commands. Recognized gestures can be transmitted wirelessly to a laptop using an **HC-05 Bluetooth module**, where a Python receiver converts the received commands into actions.

The project is being developed incrementally, starting with software testing and simulation before moving toward complete hardware integration.

---

## ⚙️ How It Works

```text
        Wrist Movement
              ↓
           MPU6050
              ↓
       STM32 Blue Pill
              ↓
      Gesture Recognition
              ↓
      ┌───────┼───────┐
      ↓       ↓       ↓
    LEFT    RIGHT     UP / DOWN
      │       │          │
      └───────┴──────────┘
              ↓
       HC-05 Bluetooth
              ↓
            Laptop
              ↓
       Python Receiver
              ↓
        Laptop Action
```

---

## 🖐️ Gesture Controls

| Gesture  | Command | Action      |
| -------- | ------- | ----------- |
| ⬅️ LEFT  | `LEFT`  | Previous    |
| ➡️ RIGHT | `RIGHT` | Next        |
| ⬆️ UP    | `UP`    | Volume Up   |
| ⬇️ DOWN  | `DOWN`  | Volume Down |

An **activation push button** is used as part of the gesture-control concept to help distinguish intentional gestures from normal wrist movement.

---

## ✨ Features

* 🖐️ Wrist-based gesture control
* 🎯 Four-direction gesture recognition
* 📡 Wireless communication using Bluetooth
* 🧠 STM32-based real-time processing
* 💻 Python-based laptop command receiver
* 🔘 Activation button for intentional gesture input
* 💡 LED indicators for development and debugging
* 🧪 Wokwi simulation for early hardware/software validation
* 🔧 Modular design for future expansion

---

## 🛠️ Hardware

| Component           | Purpose                          |
| ------------------- | -------------------------------- |
| **STM32 Blue Pill** | Main microcontroller             |
| **MPU6050**         | Motion and gesture sensing       |
| **HC-05**           | Wireless Bluetooth communication |
| **Push Button**     | Gesture activation               |
| **LEDs**            | Testing and debugging indicators |
| **ST-Link**         | STM32 programming and debugging  |
| **Breadboard**      | Hardware prototyping             |
| **Jumper Wires**    | Electrical connections           |

---

## 💻 Software

### Embedded

* Arduino framework for STM32
* C/C++
* I²C communication
* Serial communication

### Laptop

* Python
* Serial/Bluetooth communication
* Command-based laptop control

### Development & Simulation

* Wokwi
* Visual Studio Code
* Git
* GitHub

---

## 🧪 Development Journey

The project has been developed in stages rather than being assembled all at once.

### 1. Software Command Testing

Before physical hardware was available, a **fake sender and fake receiver** were created in Python.

```text
Fake Sender
     ↓
Fake Receiver
     ↓
Laptop Action
```

This allowed the command-control logic to be tested independently.

---

### 2. MPU6050 + STM32 Simulation

The STM32 Blue Pill and MPU6050 were then tested in **Wokwi**.

The simulation was used to:

* Generate and read motion data
* Recognize LEFT, RIGHT, UP and DOWN
* Test gesture recognition logic
* Provide LED feedback for detected gestures

The complete Wokwi project is available under:

```text
firmware/mpu6050/
```

---

### 3. Bluetooth Hardware Testing

The next stage moved from simulation to physical hardware.

The STM32 Blue Pill was tested with an **HC-05 Bluetooth module**.

The STM32 transmitted commands such as:

```text
RIGHT
LEFT
UP
DOWN
```

The corresponding LEDs were also used as visual debugging indicators.

The Bluetooth test firmware is available under:

```text
firmware/bluetooth/
```

---

### 4. Laptop Receiver

A Python receiver was used on the laptop to receive commands transmitted through Bluetooth.

```text
STM32
  ↓
HC-05
  ↓
Bluetooth
  ↓
Laptop
  ↓
Python Receiver
  ↓
Laptop Control
```

The receiver software is available under:

```text
software/receiver/
```

---

## 📁 Repository Structure

```text
GestureRemote/
│
├── docs/
│   ├── project_overview.md
│   ├── mpu6050_testing.md
│   ├── bluetooth_testing.md
│   └── project_progress.md
│
├── firmware/
│   ├── mpu6050/
│   │   ├── diagram.json
│   │   ├── Libraries.txt
│   │   ├── Wokwi Project.txt
│   │   └── Wokwi STM32 Bluetooth.ino
│   │
│   └── bluetooth/
│       └── BT Project.ino
│
├── hardware/
│   ├── components.md
│   └── connections.md
│
├── images/
│
├── software/
│   ├── receiver/
│   │   └── Receiver.py
│   │
│   └── testing/
│       ├── fake_sender.py
│       └── fake_receiver.py
│
├── LICENSE
└── README.md
```

---

## 📊 Current Project Status

| Stage                         | Status         |
| ----------------------------- | -------------- |
| Software command testing      | ✅ Completed    |
| MPU6050 simulation            | ✅ Completed    |
| Gesture recognition           | ✅ Tested       |
| Bluetooth hardware testing    | ✅ Completed    |
| Laptop command receiver       | ✅ Tested       |
| Activation button integration | 🔄 In Progress |
| Full hardware integration     | 🔄 In Progress |
| Final prototype               | 🔄 In Progress |

---

## 🔮 Future Development

The next development stage is to combine the independently tested modules into one complete system:

```text
MPU6050 + Push Button
          ↓
     STM32 Blue Pill
          ↓
   Gesture Recognition
          ↓
      HC-05 Bluetooth
          ↓
         Laptop
```

Further development will include final hardware assembly, integrated testing, refinement of gesture detection, and the wearable prototype.

---

## 👥 Team

* Saneesh Kumar S
* Pournamy P S
* Pranav K P
* Sreehari P R

---

## 📄 License

This project is licensed under the **MIT License**.
