#include <CapacitiveSensor.h>
#include <Adafruit_NeoPixel.h>

#define RESISTOR_PIN 9  // Shared high-value resistor pin (connected to one end of the resistor)
#define TOUCH_PIN_1 6   // First conductive material (alligator clip 1 connected to Pin 6)
#define TOUCH_PIN_2 12  // Second conductive material (alligator clip 2 connected to Pin 12)
#define LED_PIN 10      // NeoPixel data pin
#define NUM_PIXELS 2    // Number of NeoPixels

CapacitiveSensor touchSensor1 = CapacitiveSensor(RESISTOR_PIN, TOUCH_PIN_1);  // First touch sensor
CapacitiveSensor touchSensor2 = CapacitiveSensor(RESISTOR_PIN, TOUCH_PIN_2);  // Second touch sensor

Adafruit_NeoPixel strip(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);  // NeoPixel strip initialization

void setup() {
    touchSensor1.set_CS_AutocaL_Millis(0xFFFFFFFF);  // Disable auto-calibration for first sensor
    touchSensor2.set_CS_AutocaL_Millis(0xFFFFFFFF);  // Disable auto-calibration for second sensor
    Serial.begin(9600);  // Start serial communication for debugging
    strip.begin();  // Initialize the NeoPixel strip
    strip.setBrightness(80);  // Set NeoPixel brightness to 50% to reduce intensity
    strip.show();  // Initialize NeoPixels to off
}

void loop() {
    // Read touch values from both sensors
    long touchValue1 = touchSensor1.capacitiveSensor(30);  // Read first sensor
    long touchValue2 = touchSensor2.capacitiveSensor(30);  // Read second sensor

    // Print the sensor values to the serial monitor for debugging
    Serial.print("Sensor 1: ");
    Serial.print(touchValue1);
    Serial.print(" | Sensor 2: ");
    Serial.println(touchValue2);

    // Check which conductive material is touched
    if (touchValue1 > 1000 && touchValue2 <= 1000) {  
        // Only the first conductive material is touched -> Turn LEDs Red
        strip.fill(strip.Color(255, 0, 0));  // Red
    } 
    else if (touchValue2 > 1000 && touchValue1 <= 1000) {  
        // Only the second conductive material is touched -> Turn LEDs Blue
        strip.fill(strip.Color(0, 0, 255));  // Blue
    } 
    else if (touchValue1 > 1000 && touchValue2 > 1000) {  
        // Both conductive materials are touched -> Turn LEDs Purple (Red + Blue)
        strip.fill(strip.Color(255, 0, 255));  // Purple 
    } 
    else {  
        // No conductive material is touched -> Turn LEDs Off
        strip.fill(strip.Color(0, 0, 0));  // Off
    }

    // Update the NeoPixel strip
    strip.show();
    delay(10);  // Short delay for stability
}
