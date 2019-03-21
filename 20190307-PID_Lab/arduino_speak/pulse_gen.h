#ifndef PULSE_GEN_H
#define PULSE_GEN_H

#include "states.h"

class PulseGenerator
{
  private:
    int state;
    int frequency;
    int pin;

  public:
    PulseGenerator()
    {
      this->state = OFF;
      this->frequency = 0;
      this->pin = 9;
      pinMode(pin, OUTPUT);
    }

    PulseGenerator(int pin)
    {
      this->state = OFF;
      this->frequency = 0;
      this->pin = pin;
      pinMode(pin, OUTPUT);
    }

    PulseGenerator(int pin, int state, int frequency)
    {
      this->state = state;
      this->frequency = frequency;
      this->pin = pin;
      pinMode(pin, OUTPUT);
    }

    // getters / setters
    int get_state() {return this->state;}
    void set_state(int state) {this->state = state;}

    int get_frequency() {return this->frequency;}
    void set_frequency(int frequency) {this->frequency = frequency;}

    int get_pin() { return this->pin; }
    void set_pin(int pin) 
    { 
      this->pin = pin;
      pinMode(pin, OUTPUT);
    }

    void start_pulse()
    {
      if (this->state == OFF)
      {
        this->state = ON;
        //digitalWrite(this->pin, ON);
        while (this->state == ON)
        {
          digitalWrite(this->pin, HIGH);
          delay(1000/this->frequency);
          digitalWrite(this->pin, LOW);
          delay(1000/this->frequency);
        }
      }
    }

    void stop_pulse()
    {
      if (this->state == ON)
      {
        this->state = OFF;
        //digitalWrite(this->pin, OFF);
      }
    }

    void pulse()
    {
      while (this->state == ON)
      {

      }
    }

};

#endif
