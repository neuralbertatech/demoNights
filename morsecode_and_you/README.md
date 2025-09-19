**Morsecode & You**

This project lights an LED when muscle activity—measured by a BioAmp EXG Pill—exceeds a chosen threshold.
The Arduino continuously reads the EMG signal and switches the LED on or off in real time.

**Hardware**

- Arduino Uno 
- BioAmp EXG Pill 
- Breadboard
- LED 
- 220 Ω resistor 
- Jumper wires
- Sticky EMG electrodes 

**Circuit Connections**

From	                        To
BioAmp VCC	                    Arduino 5 V 
BioAmp GND	                    Arduino GND
BioAmp OUT	                    Arduino A0
Arduino D11	220 Ω resistor → LED anode (long leg)
LED cathode	                    Arduino GND

*Always include the series resistor to protect the LED and the Arduino pin.*

**Usage**

- Apply electrodes to the target muscle following the BioAmp documentation.

- Power the circuit from USB or an external 5 V source.

- Open the Serial Monitor (9600 baud) to watch the raw EMG values.

- Adjust the threshold value in the sketch until the LED turns on when the muscle contracts and off when relaxed.

**Notes & Safety**

- Keep all electrode contacts clean and dry.

- Use only the recommended power levels; the BioAmp EXG Pill is designed for safe biopotential sensing.

- This project is for educational/demo purposes only and is not a medical device.

**MIT License**

Copyright (c) 2025 NAT (NeurAlbertaTech)
