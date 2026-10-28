# ESP32 as a TCP Server

A simple implementation of TCP socket communication between an ESP32 and a Python client over Wi-Fi.

## Overview

This project demonstrates how to establish a TCP connection between an ESP32 microcontroller and a computer using Python. The ESP32 operates as a TCP server, periodically transmitting messages to a connected client.

The project provides a starting point for wireless data exchange between embedded systems and computer-based applications.

## Features

- Wi-Fi connectivity using the ESP32.
- TCP server running on port `1234`.
- Python client using the built-in `socket` library.
- Periodic message transmission from the ESP32 to the client.
- Real-time reception and terminal output of incoming data.

## System Architecture

```text
       Wi-Fi Network
             |
     +-------+-------+
     |               |
   ESP32           Computer
 TCP Server       Python Client
 Port: 1234           |
     |                |
     +---- TCP --------+
       Data Transfer
```

## Technologies Used

| Component | Technology |
|---|---|
| Microcontroller | ESP32 |
| Programming language | C++ (Arduino framework) |
| Client language | Python |
| Communication protocol | TCP/IP |
| Wireless communication | Wi-Fi |
| Python library | `socket` |

## Project Structure

```text
.
├── esp32_as_a_tcp_server.ino
├── client.py
└── README.md
```

## Hardware Requirements

- ESP32 development board.
- Computer with Python installed.
- Wi-Fi network accessible to both devices.

## Software Requirements

- Arduino IDE with ESP32 board support installed.
- Python 3.
- A terminal or command-line interface.

## Getting Started

### 1. Configure the ESP32

Open `esp32_as_a_tcp_server.ino` in Arduino IDE.

Configure the Wi-Fi credentials:

```cpp
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
```

Upload the sketch to the ESP32.

### 2. Find the ESP32 IP Address

Open the Arduino IDE Serial Monitor and set the baud rate to `115200`.

Once the ESP32 connects to Wi-Fi, its local IP address will be printed to the Serial Monitor.

Example:

```text
IP: 192.168.1.100
```

The address above is illustrative; use the IP address printed by your own ESP32.

### 3. Configure the Python Client

Open `client.py` and update the server address:

```python
HOST = "192.168.1.100"  # Replace with the ESP32's IP address
PORT = 1234
```

Ensure that the computer and ESP32 can communicate over the same network.

### 4. Run the Client

Execute the following command in the project directory:

```bash
python3 client.py
```

The client connects to the ESP32 TCP server and prints the received messages.

## Expected Output

Python terminal:

```text
hello from esp32
hello from esp32
hello from esp32
...
```

ESP32 Serial Monitor:

```text
IP: <ESP32_LOCAL_IP>
client live
client live
client live
...
```

The ESP32 sends the message `hello from esp32` approximately once per second while a client remains connected.

## How It Works

1. **Wi-Fi initialization:** The ESP32 connects to the configured wireless network.
2. **TCP server initialization:** The ESP32 starts listening for client connections on port `1234`.
3. **Client connection:** The Python program establishes a TCP connection to the ESP32 using its IP address and port.
4. **Data transmission:** The ESP32 sends a text message using `client.println()`.
5. **Data reception:** The Python client receives bytes through `socket.recv()`, decodes them into text, and prints the received data.
6. **Continuous communication:** The connection remains active while the client stays connected and the server continues transmitting.

## Potential Applications

This communication architecture can be extended for:

- Wireless transmission of IMU and sensor measurements.
- Real-time robot telemetry monitoring.
- Sending robot orientation and movement data to a computer.
- Visualizing sensor data using Python plotting libraries.
- Communication between embedded devices and computer-based control systems.

## Limitations

- The current implementation transmits a fixed text message rather than live sensor data.
- The server handles one connected client at a time.
- The Python client does not currently implement automatic reconnection or graceful shutdown.
- The client stores received data in memory without a defined message-processing or data-storage strategy.
- Both devices must have network connectivity that permits TCP communication.

## Future Improvements

- Transmit real-time sensor readings from the ESP32.
- Add structured data formats such as JSON or binary packets.
- Implement robust connection handling and automatic reconnection.
- Log incoming data to CSV files for analysis.
- Develop a real-time telemetry dashboard using Python.
- Extend the system for robotics experiments involving sensor fusion and control.

## Learning Outcomes

- Understanding TCP client–server architecture.
- Implementing socket communication between an embedded device and a computer.
- Configuring Wi-Fi communication using ESP32.
- Receiving and processing network data in Python.
- Establishing a foundation for wireless robotics telemetry.
