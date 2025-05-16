// PIR Sensor
const int pirPin = 2;

// LEDs
const int redLed = 3;
const int greenLed = 4;


// Ultrasonic Sensor
const int trigPin = 9;
const int echoPin = 10;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // PIR Motion Detection
  int motionDetected = digitalRead(pirPin);
  if (motionDetected == HIGH) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    Serial.println("PIR: Motion Detected");
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    Serial.println("PIR: No Motion");
  }

  // Ultrasonic Sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  Serial.print("Ultrasonic Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000);
}
