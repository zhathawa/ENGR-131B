#ifndef ULTRA_H
#define ULTRA_H

#include "states.h"

class Ultrasonic
{
	private:
		// software stuff
		int state;

		// distance to ball
		float distance;

		// should probably use an array
		// how long did it take to receive signal back
		long duration;
		
		// hardware
		int trig;
		int echo;

	public:
		// constructors
		Ultrasonic()
		{
			this->state = 0;
			this->distance = 0.0;
			this->duration = 0.0;
			this->trig = 9;
			this->echo = 10;
		};
	
		Ultrasonic(int trig, int echo)
		{
			this->state = 0;
			this->distance = 0.0;
			this->duration = 0.0;
			this->trig = trig;
			this->echo = echo;
		};

		// cleanup
		~Ultrasonic() {};

		// getters / setters
		int  get_state() { return this->state; }
		void set_state(int state) { this->state = state; }
	
		float get_distance() { return this->distance; }
		void  set_distance(float d} { distance = d; }

		long get_duration() { return this->duration; }
		void set_duration(long d) { duration = d; }

		int get_trig() { return this->trig; }
		void set_trig(int trig) { this->trig = trig; }

		int get_echo() { return this->echo; }
		void set_echo(int echo) { this->echo = echo; }

		// TODO: ADD ultrasonic sensor control code
};

#endif 	
