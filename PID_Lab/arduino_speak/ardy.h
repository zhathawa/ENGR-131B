#ifndef ARDY_H
#define ARDY_H

#include "joystick.h"
#include "pulse_gen.h"
#include "ultra.h"

class Ardy
{
  private:
	// TODO: PIN Tracking

	// TODO: State tracking


	// objects
    Joystick joy;
    PulseGenerator pgen;
	Ultrasonic ultra;

  public:
    Ardy(){};
    ~Ardy(){};
    
    Joystick get_joystick() { return this->joy; }
    PulseGenerator get_pgen() { return this->pgen; }
	

    // PULSE GENERATOR STUFF
    void set_pgen_frq(int frq) { this->pgen.set_frequency(frq); }
    void set_pgen_state(int state) { this->pgen.set_state(state); }

	// actually turn the pulse generator on
    void pulse()
    {
      this->pgen.pulse();
    }

	// TODO: JOYSTICK STUFF

	// TODO: ULTRASONIC SENSOR STUFF
	
	
	

};

#endif
