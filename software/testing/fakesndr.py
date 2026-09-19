import socket
import time

HOST = "127.0.0.1"
PORT = 5000

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((HOST, PORT))

print("Gesture Remote Simulator")
print("------------------------")
print("Type RIGHT / LEFT / UP / DOWN")
print("Type EXIT to stop")
print()

while True:

    command = input("Command: ").strip().upper()

    if command == "EXIT":
        break

    if command in ["RIGHT", "LEFT", "UP", "DOWN"]:

        print("Sending in 3 seconds...")
        time.sleep(3)

        client.sendall((command + "\n").encode())
        print("Sent:", command)

    else:
        print("Invalid command")

client.close()