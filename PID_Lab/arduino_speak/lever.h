#ifndef LEVER_H
#define LEVER_H

#include "states.h"
#include <Servo.h>

class Lever
{
  private:
    int pin;
    int ang;

    Servo my_servo;

  public:
    Lever()
    {
      this->pin = 6;
      // this->my_servo.attach(this->pin);
      this->ang = this->my_servo.read();
    };

    Lever(int pin)
    {
      this->pin = pin;
      this->my_servo.attach(this->pin);
      this->ang = this->my_servo.read();
    };

    Lever(int pin, int ang)
    {
      this->pin = pin;
      this->my_servo.attach(this->pin);
      this->ang = this->my_servo.read();
    };


    ~Lever() { my_servo.detach(); };

    int get_pin() { return this->pin; }
    void set_pin(int pin)
    {
      this->pin = pin;
      this->my_servo.attach(pin);
    }

    int get_ang()
    {
      //this->ang = my_servo.read();
      //return this->ang;

      return my_servo.read();
    }

    void set_ang(int ang)
    {
      /*
	    Serial.print("Current angle: ");
	    Serial.print(this->ang);
      Serial.print("\tMoving to: ");
	    Serial.println(ang);
      */

      this->ang = ang;
      my_servo.write(this->ang);
      delay(150);
      //move(ang);
    }

    void info()
    {
      Serial.println(get_ang());
    }

    void init_attach()
    {
      my_servo.attach(this->pin);
    }
};

#endif
