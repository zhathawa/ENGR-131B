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


	// TODO: JOYSTICK STUFF
    Joystick get_joystick() { return this->joy; }

	void set_joy_state(int state) { this->joy.set_state(state); }

    // PULSE GENERATOR STUFF
    PulseGenerator get_pgen() { return this->pgen; }

    void set_pgen_frq(int frq) { this->pgen.set_frequency(frq); }
    void set_pgen_state(int state) { this->pgen.set_state(state); }

	// actually turn the pulse generator on
    void pulse()
    {
      this->pgen.pulse();
    }

	// TODO: ULTRASONIC SENSOR STUFF
	Ultrasonic get_ultra() { return this->ultra; }

	// set key features
	void set_ultra_state(int state) { this->ultra.set_state(state); }
	void set_ultra_trig(int trig) { this->ultra.set_trig(trig); }
	void set_ultra_echo(int echo) { this->ultra.set_echo(echo); }
	void set_pins(int trig, int echo)
	{
		set_ultra_trig(trig);
		set_ultra_echo(echo);
	}

	// turn on ultrasonic
	void start_ultra()
	{
		this->ultra.start();
	}


};

#endif
