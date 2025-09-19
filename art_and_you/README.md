# Demo Nights #3
# Capacitive Touch Sensor with NeoPixels

This Arduino project uses capacitive touch sensors to control NeoPixel LEDs. When conductive materials connected to the capacitive sensor pins are touched, the NeoPixels change color accordingly.

# Components Used: 


- Flora Board
- Adafruit NeoPixels (or compatible WS2812 LEDs)
- High-value resistor (e.g., 1MΩ - 10MΩ)
- Conductive thread
- Conductive fabric
- Alligator clips (to connect the conductive materials)

# Wiring Diagram:

  Component          Arduino Pin
  
  Resistor Pin         9
  Touch Sensor1        6
  Touch Sensor2       12
  NeoPixel Data       10

# Installation & Setup

  Install the Required Libraries:
    Install the Adafruit NeoPixel library from the Arduino Library Manager.
    Install the CapacitiveSensor library by Paul Badger from the Arduino Library Manager.

  Upload the Code:
    Copy and paste the provided Arduino sketch into the Arduino IDE.
    Select the correct board and COM port(USB).
    Upload the code to your Arduino.

# How It Works
  
  The capacitive touch sensors detect when a user touches the conductive materials.
  The NeoPixels change color based on the touch input:
  Red: If only the first sensor is touched.
  Blue: If only the second sensor is touched.
  Purple: If both sensors are touched simultaneously.
  Off: If no sensor is touched.

# Code Explanation

  Capacitive Sensors Setup: A high-value resistor is used to measure capacitance changes.
  NeoPixel Configuration: Uses the Adafruit_NeoPixel library for LED control.
  Loop Function: 
    Reads the touch sensor values.
    Determines the color based on sensor activation.
    Updates the NeoPixel LEDs accordingly.

# Troubleshooting

1) LEDs Not Lighting Up?
  Check wiring connections, especially the data pin.
  Ensure the NeoPixel library is correctly installed.
  Verify that the power supply can handle the LED strip.

2) Sensors Not Responding?
  Try adjusting the threshold values in the code.
  Use a higher-value resistor for better sensitivity.
  Ensure the conductive material is properly connected.

# Future Improvements

  Add more touch sensors for additional interactions.
  Implement dynamic brightness control.
  Use an OLED display to show sensor values in real-time.

# License
This project is open-source. Feel free to modify and improve it!
