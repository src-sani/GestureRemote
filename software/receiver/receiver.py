import serial
import pyautogui

ser = serial.Serial("COM6", 9600, timeout=1)

print("Bluetooth receiver started.")
print("Waiting for commands...")

while True:
    command = ser.readline().decode("utf-8", errors="ignore").strip()

    if command:
        print("Received:", command)

        if command == "RIGHT":
            pyautogui.press("right")

        elif command == "LEFT":
            pyautogui.press("left")

        elif command == "UP":
            pyautogui.press("volumeup")

        elif command == "DOWN":
            pyautogui.press("volumedown")