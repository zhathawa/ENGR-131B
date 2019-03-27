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
      this->my_servo.attach(this->pin);
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
      this->ang = my_servo.read();
      return this->ang;
    }

    void set_ang(int ang)
    {
      this->ang = ang;
      my_servo.write(this->ang);
    }

    void info()
    {
      get_ang();
      Serial.println(this->ang);
    }

    void init_write()
    {
      for (int i = 0; i <= 180; i++)
        {
          my_servo.write(i);
          delay(500);
        }
        Serial.println("INITED!");
    }
};

#endif
