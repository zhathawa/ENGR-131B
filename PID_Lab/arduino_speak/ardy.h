#ifndef ARDY_H
#define ARDY_H

#include "joystick.h"
#include "pulse_gen.h"

class Ardy
{
  private:
    PulseGenerator pgen;
    Joystick joy;

  public:
    Ardy(){};
    ~Ardy(){};
    
    PulseGenerator get_pgen() { return this->pgen; }
    Joystick get_joystick() { return this->joy; }

    void set_pgen_frq(int frq) { this->pgen.set_frequency(frq); }
    void set_pgen_state(int state) { this->pgen.set_state(state); }

};

#endif
