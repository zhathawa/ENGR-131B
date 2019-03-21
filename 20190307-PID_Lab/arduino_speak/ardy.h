#ifndef ARDY_H
#define ARDY_H

#include "joystick.h"
#include "pulse_gen.h"

class Ardy
{
  private:
    PulseGenerator pgen;
    JoyStick joy;

  public:
    PulseGenerator get_pgen() { return this->pgen; }
    JoyStick get_joystick() { return this->joy; }
    
};

#endif
