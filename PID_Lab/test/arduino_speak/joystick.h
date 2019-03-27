#ifndef JOY_H
#define JOY_H

#include "states.h"

class Joystick
{
  private:
	// key software stuff
    int state;
    int sensitivity;

	// key hardware stuff
	int pin;

  public:
    Joystick()
    {
      this->state = OFF;
      this->sensitivity = 0;
      this->pin = 10;
    }

    Joystick(int sensitivity)
    {
      this->state = OFF;
      this->sensitivity = sensitivity;
    }

    Joystick(int state, int sensitivity)
    {
      this->state = state;
      this->sensitivity = sensitivity;
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
    
};

#endif
