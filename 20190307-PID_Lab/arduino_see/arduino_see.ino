// use digital pins for sending trigger and receiving echo
int trig_pin = 9;
int echo_pin = 10;

// long type for duration b/c lots of decimals
long duration;
// calculate and report distance as float
float distance;

void setup() {
  // Trigger is an Output
  pinMode(trig_pin, OUTPUT);

  // Echo is an Input
  pinMode(echo_pin, INPUT);
  Serial.begin(115200);
}

void loop() {
  // clear the trigger from ultrasonic
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);

  // send a 10 us pulse to trigger
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  // read echo pin to get the total time to the object and back
  duration = pulseIn(echo_pin, HIGH);

  // 0.034 cm/us is speed of sound
  // 2 is because the sound wave goes to the object and reflects back
  distance = duration * 0.034/2;

  // print to monitor
  Serial.print("Duration: ");
  Serial.print(duration);
  Serial.print('\t');
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);
}
