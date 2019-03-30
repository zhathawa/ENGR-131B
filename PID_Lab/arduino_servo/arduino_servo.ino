#include <Servo.h>

Servo lever;
int servo_val;
int sensitivity;

void setup() {
  Serial.begin(115200);
  lever.attach(6);
  servo_val = lever.read();
  sensitivity = 20;
}

void loop() {
  /*
  lever.write(servo_val - 1 * sensitivity);
  servo_val = lever.read();
  Serial.println(servo_val);
  if (servo_val <= 0 || servo_val >= 180)
  {
  sensitivity = -sensitivity;
  }

  delay(200);
  */
}
