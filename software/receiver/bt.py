import serial

PORT = "COM6"
BAUDRATE = 9600

ser = serial.Serial(PORT, BAUDRATE, timeout=1)

print("================================")
print(" Bluetooth Serial Monitor")
print("================================")
print(f"Connected to {PORT} @ {BAUDRATE}")
print("Waiting for data...\n")

while True:
    try:
        data = ser.readline().decode("utf-8", errors="ignore").strip()

        if data:
            print(data)

    except KeyboardInterrupt:
        print("\nBluetooth Serial Monitor stopped.")
        ser.close()
        break