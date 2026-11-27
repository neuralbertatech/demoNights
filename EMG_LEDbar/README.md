# Muscle-Powered LED Bar Graph (EMG)

Turn a fist clench into a live light display. This project reads electrical signals from your forearm muscles using a **BioAmp EXG Pill** and an **Arduino Uno**, then lights up a 9-LED bar graph based on how hard you flex.

Based on the open-source [Upside Down Labs BioAmp EXG Pill](https://github.com/upsidedownlabs/BioAmp-EXG-Pill) repository, tweaked for a 9-LED breadboard setup on pins 2–10.

---

## What You Need

* **1×** Arduino Uno (plus USB cable)
* **1×** BioAmp EXG Pill + electrode cable + 3 gel electrode pads
* **1×** Breadboard
* **9×** 5mm LEDs (any color combo)
* **9×** Resistors (220 Ω or 330 Ω work best; anything from 200 Ω to 470 Ω is safe)
* Jumper wires

---

## Wiring

### 1. Power Rails
* Arduino **5V** → Breadboard **`+`** rail
* Arduino **GND** → Breadboard **`-`** rail

### 2. LED Bar (9 LEDs)
* **Long leg (anode / `+`)** → Arduino digital pins **2 through 10**
* **Short leg (cathode / `-`)** → Resistor → Breadboard **`-`** rail

### 3. BioAmp EXG Pill
* **VCC** → Breadboard **`+`** rail (5V)
* **GND** → Breadboard **`-`** rail (GND)
* **OUT** → Arduino **A0**

### 4. Electrode Placement
* **IN+ & IN-:** Place both along the inside of your forearm muscle (flex your fist to feel which muscle moves).
* **REF:** Place on a bony spot with little muscle—like your elbow or the back of your hand.

---

## How to Run It

1. Open the `.ino` file in the **Arduino IDE**.
2. Select **Arduino Uno** and your port, then hit **Upload**.
3. *(Optional)* Open **Tools → Serial Plotter** and set the baud rate to **115200** to watch your raw EMG signal and smoothed envelope live.
4. Clench your fist and the LED bar should climb with your grip strength.

---

## Customizing for Your Setup

Everyone's skin impedance and muscle signal strength are a little different, so you'll probably want to tweak a couple of lines:

* **LED Direction (`led_bar[]`):** Right now it fills from pin `10` down to `2`. Swap it to `{2, 3, 4, 5, 6, 7, 8, 9, 10}` if your bar fills backwards.
* **Sensitivity (`led_bar_level`):** Look for ` int led_bar_level = map(envelop, 0, 20, 0, total_leds);`.
  * Adjust '20' higher if LEDs max out too easily, or lower if they barely light up


---

## Quick Troubleshooting

* **All LEDs are stuck ON:** Unplug your laptop charger. Wall power introduces 50/60 Hz noise that swamps EMG signals. Running on battery fixes this immediately.
* **None of the LEDs turn on:** Double-check that the short leg of each LED is connected to the `-` rail, and make sure your breadboard's `-` rail isn't split in the middle.
* **Signal is flat in Serial Plotter:** Press the gel pads down firmly and make sure the **REF** electrode hasn't popped loose.

---

## Credits

Core bandpass filter and envelope detection adapted from [Upside Down Labs](https://github.com/upsidedownlabs/BioAmp-EXG-Pill) (MIT License).