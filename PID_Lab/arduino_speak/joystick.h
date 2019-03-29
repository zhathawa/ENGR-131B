#ifndef JOY_H
#define JOY_H

#include "states.h"

class Joystick
{
  private:
  	// key software stuff
    int state;
    int sensitivity;

    int lower_limit;
    int upper_limit;

  	// key hardware stuff
  	int pin;

  public:
    Joystick()
    {
      this->state = OFF;
      this->sensitivity = 5;
      this->pin = A0;

      this->lower_limit = 1 / 5 * 1023;
      this->upper_limit = 4 / 4 * 1023;
    }

    Joystick(int sensitivity)
    {
      this->state = OFF;
      this->sensitivity = sensitivity;
      this->pin = A0;
      this->lower_limit = 1 / 5 * 1023;
      this->upper_limit = 4 / 4 * 1023;
    }

    Joystick(int state, int sensitivity)
    {
      this->state = state;
      this->sensitivity = sensitivity;
      this->pin = A0;
      this->lower_limit = 1 / 5 * 1023;
      this->upper_limit = 4 / 4 * 1023;
    }

    ~Joystick(){};

    // getters / setters
    int get_state() {return this->state;}
    void set_state(int state) {this->state = state;}

    int get_sensitivity() {return this->sensitivity;}
    void set_sensitivity(int sensitivity) {this->sensitivity = sensitivity;}

    void info()
	  {
	    Serial.print("State: ");
	    Serial.println(this->state);
	    Serial.print("Sensitivity: ");
	    Serial.println(this->sensitivity);
	  }

    int dircts()
    {
      // update voltage
      int val = analogRead(this->pin);
      if (val > this->upper_limit)
      {
        return UP;
      }
      else if (val < this->lower_limit)
      {
        return DOWN;
      }
      else
      {
        return NEWT;
      }
    }

    void joy_run();

};

void Joystick::joy_run()
{
  // migrate timnig code to Servo

}


#endif
