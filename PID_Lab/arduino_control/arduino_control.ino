#include <Servo.h>

int trig = 11;
int echo = 10;

Servo lever;
int servo_val;

// Control variables
long duration;
float PID_error = 0;
float previous_error = 0;
float elapsedTime, Time, timePrev;
float PID_value = 0;
int servo_output;
int set_duration = 600;
int last_set_duration = 0;

//PID constants
//////////////////////////////////////////////////////////
float kp = 2.5;   float ki = 0;   float kd = 1.1;
//////////////////////////////////////////////////////////

int PID_p = 0;    int PID_i = 0;    int PID_d = 0;
float last_kp = 0;
float last_ki = 0;
float last_kd = 0;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  lever.attach(6);
  servo_val = lever.read();

  Serial.begin(115200);
}

void loop()
{
  // digitalWrite(trig, LOW);
  // delayMicroseconds(2);
  //
  // digitalWrite(trig, HIGH);
  // delayMicroseconds(50);
  // digitalWrite(trig, LOW);
  //
  // duration = pulseIn(echo, HIGH);

  duration = readUltra();
  Serial.print(duration);
  Serial.print(" :: ");
  PID_error = set_duration - duration;
  // Calulate P
  PID_p = 0.01*kp*PID_error;
  // Calculate I
  PID_i = 0.01*PID_i + (ki * PID_error);

  // Calculate D
  timePrev = Time;
  Time = millis();
  elapsedTime = (Time - timePrev) / 1000;
  PID_d = 0.01*kd*((PID_error - previous_error)/elapsedTime);

  PID_value = PID_p + PID_i + PID_d;
  if (PID_value > 42) { PID_value = 42; }
  if (PID_value < -138) { PID_value = -138; }

  Serial.print(PID_value);
  Serial.print(" :: ");

  servo_output = 140 + PID_value;
  Serial.println(servo_output);

  lever.write(servo_output);
  previous_error = PID_error;

  delay(150);
}

long readUltra()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(50);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  if (duration > 100000)
  {
    duration = 0;
  }
  return duration;
}
