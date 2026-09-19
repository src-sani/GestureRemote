import socket
import pyautogui

HOST = "127.0.0.1"
PORT = 5000

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen(1)

print("Gesture Remote Receiver")
print("-----------------------")
print("Waiting for connection...")

connection, address = server.accept()

print("Connected!")
print("Waiting for commands...")
print()

while True:

    data = connection.recv(1024)

    if not data:
        break

    commands = data.decode("utf-8").splitlines()

    for command in commands:

        command = command.strip().upper()

        print("Received:", command)

        if command == "RIGHT":
            pyautogui.press("right")
            print("→ Next slide")

        elif command == "LEFT":
            pyautogui.press("left")
            print("← Previous slide")

        elif command == "UP":
            pyautogui.press("up")
            print("↑ UP")

        elif command == "DOWN":
            pyautogui.press("down")
            print("↓ DOWN")

connection.close()
server.close()