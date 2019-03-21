#ifndef PULSE_GEN_H
#define PULSE_GEN_H

#include "states.h"

class PulseGenerator
{
  private:
    int state;
    int frequency;

  public:
    PulseGenerator()
    {
      this->state = OFF;
      this->frequency = 0;
    }

    PulseGenerator(int frequency)
    {
      this->state = ON;
      this->frequency = frequency;
    }

    PulseGenerator(int state, int frequency)
    {
      this->state = state;
      this->frequency = frequency;
    }

    // getters / setters
    int get_state() {return this->state;}
    void set_state(int state) {this->state = state;}

    int get_frequency() {return this->frequency;}
    void set_frequency(int frequency) {this->frequency = frequency;}

    void change_pin(int value, int pin_num)
    {
      
    }
};

#endif
