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
      // this->ang = ang;
      // my_servo.write(this->ang);
      // delay(50);
      move(ang);
    }

    void info()
    {
      Serial.println(get_ang());
    }

    void init_attach()
    {
      my_servo.attach(this->pin);
    }

    void move(int ang)
    {
      int del = 50;
      int step = 10;
      if (this->ang - ang < step && this->ang - ang > -step)
      {
        this->ang = ang;
        my_servo.write(this->ang);
        return;
      }
      int N = this->ang / step;
      if (this->ang < ang)
      {
        for (int i = 1; i < N; i++)
        {
          this->ang += step;
          my_servo.write(this->ang);
          delay(del);
        }
        if (this->ang != ang)
        {
          this->ang = ang;
          my_servo.write(this->ang);
          delay(del);
        }
      }
      else
      {
        for (int i = 1; i < N; i++)
        {
          this->ang -= step;
          my_servo.write(this->ang);
          delay(del);
        }
        if (this->ang != ang)
        {
          this->ang = ang;
          my_servo.write(this->ang);
          delay(del);
        }
      }

    }
};

#endif
