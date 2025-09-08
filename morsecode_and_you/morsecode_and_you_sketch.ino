const int emgPin = A0;    // BioAmp EXG Pill OUT
const int ledPin = 11;    // LED anode via resistor to D11

// Adjust based on your baseline EMG values
int threshold = 525;      

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  // For debugging values
}

void loop() {
  int emgValue = analogRead(emgPin);

  Serial.println(emgValue);  // See raw values in Serial Monitor

  if (emgValue > threshold) {
    digitalWrite(ledPin, HIGH);  // Contracted muscle -> LED ON
  } else {
    digitalWrite(ledPin, LOW);   // Relaxed muscle -> LED OFF
  }

  delay(8); // small delay for stability
}
