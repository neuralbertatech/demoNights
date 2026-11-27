// EMG LED BarGraph - BioAmp EXG Pill
// https://github.com/upsidedownlabs/BioAmp-EXG-Pill

#define SAMPLE_RATE 500
#define BAUD_RATE 115200
#define INPUT_PIN A0
#define BUFFER_SIZE 128

int circular_buffer[BUFFER_SIZE];
int data_index, sum;

// LED pins matching your Tinkercad layout (Green -> Yellow -> Red: pins 10 down to 2)
// Swap to {2, 3, 4, 5, 6, 7, 8, 9, 10} if you want it to fill in the opposite direction
int led_bar[] = {10, 9, 8, 7, 6, 5, 4, 3, 2};
int total_leds = sizeof(led_bar) / sizeof(led_bar[0]);

void setup() {
  Serial.begin(BAUD_RATE);
  
  for (int i = 0; i < total_leds; i++) {
    pinMode(led_bar[i], OUTPUT);
  }
}

void loop() {
  // Calculate elapsed time for fixed 500 Hz sampling
  static unsigned long past = 0;
  unsigned long present = micros();
  unsigned long interval = present - past;
  past = present;

  static long timer = 0;
  timer -= interval;

  if (timer < 0) {
    timer += 1000000 / SAMPLE_RATE;

    // 1. Read raw EMG signal and apply 74.5 - 149.5 Hz bandpass filter
    int sensor_value = analogRead(INPUT_PIN);
    int signal = EMGFilter(sensor_value);

    // 2. Get signal envelope (smoothed amplitude)
    int envelop = getEnvelop(abs(signal));

    // 3. Map envelope to the number of LEDs to light up
    // Adjust '100' higher if LEDs max out too easily, or lower if they barely light up
    int led_bar_level = map(envelop, 0, 20, 0, total_leds); 
    led_bar_level = constrain(led_bar_level, 0, total_leds);

    // 4. Update LED bar
    for (int i = 0; i < total_leds; i++) {
      if (i < led_bar_level) {
        digitalWrite(led_bar[i], HIGH);
      } else {
        digitalWrite(led_bar[i], LOW);
      }
    }

    // Optional: view signal & envelope in Arduino Serial Plotter
    Serial.print(signal);
    Serial.print(",");
    Serial.println(envelop);
  }
}

// Moving-average envelope detector
int getEnvelop(int abs_emg) {
  sum -= circular_buffer[data_index];
  sum += abs_emg;
  circular_buffer[data_index] = abs_emg;
  data_index = (data_index + 1) % BUFFER_SIZE;
  return (sum / BUFFER_SIZE) * 2;
}

// Band-Pass Butterworth IIR digital filter (74.5 - 149.5 Hz at 500 Hz sample rate)
float EMGFilter(float input) {
  float output = input;
  {
    static float z1, z2;
    float x = output - 0.05159732 * z1 - 0.36347401 * z2;
    output = 0.01856301 * x + 0.03712602 * z1 + 0.01856301 * z2;
    z2 = z1;
    z1 = x;
  }
  {
    static float z1, z2;
    float x = output - -0.53945795 * z1 - 0.39764934 * z2;
    output = 1.00000000 * x + -2.00000000 * z1 + 1.00000000 * z2;
    z2 = z1;
    z1 = x;
  }
  {
    static float z1, z2;
    float x = output - 0.47319594 * z1 - 0.70744137 * z2;
    output = 1.00000000 * x + 2.00000000 * z1 + 1.00000000 * z2;
    z2 = z1;
    z1 = x;
  }
  {
    static float z1, z2;
    float x = output - -1.00211112 * z1 - 0.74520226 * z2;
    output = 1.00000000 * x + -2.00000000 * z1 + 1.00000000 * z2;
    z2 = z1;
    z1 = x;
  }
  return output;
}