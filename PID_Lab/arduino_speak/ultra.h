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
		float prev_distance;

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
			this->state = ON;
			this->distance = 0.0;
			this->prev_distance = 0.0;
			this->duration = 0.0;
			this->trig = 11;
			this->echo = 10;
			// Trigger is an Output
			pinMode(this->trig, OUTPUT);
			// Echo is an Input
			pinMode(this->echo, INPUT);
		};

		Ultrasonic(int trig, int echo)
		{
			this->state = OFF;
			this->distance = 0.0;
			this->prev_distance = 0.0;
			this->duration = 0.0;
			this->trig = trig;
			this->echo = echo;

			// Trigger is an Output
			pinMode(this->trig, OUTPUT);
			// Echo is an Input
			pinMode(this->echo, INPUT);
		};

		// cleanup
		~Ultrasonic() {};

		// getters / setters
		int  get_state() { return this->state; }
		void set_state(int state) { this->state = state; }

		float get_distance() { return this->distance; }
		void  set_distance(float d) { distance = d; }

		float get_prev_distance() { return this->distance; }
		void set_prev_distance(float d) { prev_distance = d; }

		long get_duration() { return this->duration; }
		void set_duration(long d) { duration = d; }

		int get_trig() { return this->trig; }
		void set_trig(int trig) { this->trig = trig; }

		int get_echo() { return this->echo; }
		void set_echo(int echo) { this->echo = echo; }

		void info()
		{
			start();
			Serial.println(this->duration);
		}


		void start()
		{
			// Michael's code from arduino_see.ino
			// clear
			digitalWrite(this->trig, LOW);
			delayMicroseconds(2);

			// 10 us pulse
			digitalWrite(this->trig, HIGH);
			delayMicroseconds(10);
			digitalWrite(this->trig, LOW);

			// how long?
			this->duration = pulseIn(this->echo, HIGH);

			// fancy math
			// speed of sound: 0.034 cm/us
			// 2 to account for there and back
			this->distance = this->duration * 0.034/2;

			// if we want to print this to the console, we can
		}
};

#endif
