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
    Ardy() {};
    PulseGenerator get_pgen() { return this->pgen; }
    Joystick get_joystick() { return this->joy; }


    
    
};

#endif
