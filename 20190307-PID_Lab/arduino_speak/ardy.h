#ifndef ARDY_H
#define ARDY_H

#include "pulse_gen.h"

class Ardy
{
  private:
    PulseGenerator pgen;

  public:
    PulseGenerator get_pgen() { return this->pgen; }
};

#endif
