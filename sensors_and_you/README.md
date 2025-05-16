# Motion and Distance Detection System with LEDs

This Arduino project combines a **PIR motion sensor** and an **ultrasonic distance sensor** to detect motion and measure distance in real time. Based on the sensor inputs, **red** and **green LEDs** indicate whether motion is detected.

## Features

- Detects motion using a PIR sensor
- Measures distance using an HC-SR04 ultrasonic sensor
- Displays motion and distance data in the Serial Monitor
- Uses LEDs for visual feedback:
  - Red LED: Motion detected
  - Green LED: No motion

## Components Used

- Arduino Uno 
- PIR Motion Sensor
- HC-SR04 Ultrasonic Sensor
- Two LEDs
- Resistors (220Ω for LEDs)
- Breadboard and jumper wires

## Pin Connections

| Component           | Arduino Pin |
|---------------------|-------------|
| PIR Sensor (OUT)    | D2          |
| First LED           | D3          |
| Second LED          | D4          |
| Ultrasonic Trig     | D9          |
| Ultrasonic Echo     | D10         |

## How It Works

1. The PIR sensor detects motion.
   - If motion is detected, the **red LED turns on** and the green turns off.
   - If no motion is detected, the **green LED turns on** and the red turns off.

2. The HC-SR04 ultrasonic sensor calculates distance by sending a sound pulse and timing how long it takes to receive the echo.
   - The distance is printed to the Serial Monitor in centimeters.

3. The loop repeats every 1 second.

## Serial Output Example

