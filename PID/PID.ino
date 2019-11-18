
#include "ultrasonic.h"

Ultrasonic* ultra;

void setup() {
  // put your setup code here, to run once:
  ultra = new Ultrasonic();
  Serial.begin(9600);
  
}

void loop() { 
  // put your main code here, to run repeatedly:
  ultra->calcDistance();
  //Serial.println("Duration: %0.3f\tDistance: %0.3f", ultra->getDuration(), ultra->getCurrentDistance());
  //Serial.print("Duration: ");
  Serial.println(ultra->getDuration());
  //Serial.print("\tDistance: ");
  //Serial.print(",");
  //Serial.println(ultra->getCurrentDistance());
}
