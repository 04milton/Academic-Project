// PWM based DC motor speed controller (Arduino Nano + L293D)

int volume_pin = A0;      // Potentiometer wiper
int read_ADC;

int pwm_pin = 11;         // L293D Enable A (EN1,2) -> PWM
int in1_pin = 8;          // L293D Input A (IN1)
int in2_pin = 9;          // L293D Input B (IN2)

int duty_cycle;
int duty_cycle_lcd;

void setup() {
  pinMode(volume_pin, INPUT);
  pinMode(pwm_pin, OUTPUT);
  pinMode(in1_pin, OUTPUT);
  pinMode(in2_pin, OUTPUT);

  // Motor direction (forward). Swap HIGH/LOW to reverse.
  digitalWrite(in1_pin, HIGH);
  digitalWrite(in2_pin, LOW);
}

void loop() {
  read_ADC = analogRead(volume_pin);

  duty_cycle = map(read_ADC, 0, 900, 0, 200);
  duty_cycle_lcd = map(read_ADC, 0, 1023, 0, 100);

  if (duty_cycle_lcd > 0) {
    analogWrite(pwm_pin, duty_cycle);
  } else {
    digitalWrite(pwm_pin, LOW);
  }
}