
#include "ultrasonic.h"

Ultrasonic::Ultrasonic() {
  // setting defaults based on testing setup
  this->echo = 3;
  this->trigger = 9;

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  this->duration = 0;
  this->current_distance = 0;
}

Ultrasonic::Ultrasonic(int echo, int trigger) {
  // store this info
  this->echo = echo;
  this->trigger = trigger;

  // set the pin modes
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT); 
  
  this->duration = 0;
  this->current_distance = 0;
}

int Ultrasonic::getEcho() { return this->echo; }
void Ultrasonic::setEcho(int echo) {
  this->echo = echo;
}

int Ultrasonic::getTrigger() { return this->trigger; }
void Ultrasonic::setTrigger(int trigger) {
  this->trigger = trigger;
}

float Ultrasonic::getDuration() { return this->duration; }
void Ultrasonic::setDuration(float duration) {
  this->duration = duration;
}

float Ultrasonic::getCurrentDistance() { return this->current_distance; }
void Ultrasonic::setCurrentDistance(float currentDistance) {
  this->current_distance = currentDistance;
}

// took this from previous code
// this will be our input to the PID code
float Ultrasonic::calcDistance() {
  // clear out the ultrasonic
  digitalWrite(this->trigger, LOW);
  delayMicroseconds(2);

  // pulse for 10 us
  digitalWrite(this->trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(this->trigger, LOW);

  // figure out how long it took to return
  this->duration = pulseIn(this->echo, HIGH);

  this->current_distance = this->duration * 0.034/2;
}
