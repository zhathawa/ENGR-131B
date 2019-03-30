#ifndef JOY_H
#define JOY_H

#include "states.h"

class Joystick
{
  private:
  	// key software stuff
    int state;
    int sensitivity;

    float lower_limit;
    float upper_limit;

  	// key hardware stuff
  	int pin;

  public:
    Joystick()
    {
      this->state = OFF;
      this->sensitivity = 5;
      this->pin = A0;

      this->lower_limit = (1. / 5.) * 1023.;
      this->upper_limit = (4. / 5.) * 1023.;
    }

    Joystick(int sensitivity)
    {
      this->state = OFF;
      this->sensitivity = sensitivity;
      this->pin = A0;
      this->lower_limit = 1. / 5. * 1023.;
      this->upper_limit = 4. / 5. * 1023.;
    }

    Joystick(int state, int sensitivity)
    {
      this->state = state;
      this->sensitivity = sensitivity;
      this->pin = A0;
      this->lower_limit = 1. / 5. * 1023.;
      this->upper_limit = 4. / 5. * 1023.;
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
	    Serial.print(this->state);
	    Serial.print("Sensitivity: ");
	    Serial.println(this->sensitivity);
	  }

    int directions()
    {
      // update voltage
      int val = analogRead(14);
      // Serial.print("Joystick sent: ");
      // Serial.print(val);
      // Serial.print(": ");
      // Serial.print(upper_limit);
      // Serial.print(": ");
      // Serial.println(lower_limit);

      if (val > this->upper_limit)
      {
        // Serial.println("UP");
        return UP;
      }
      else if (val < this->lower_limit)
      {
        // Serial.println("DOWN");
        return DOWN;
      }
      else
      {
        // Serial.println("Nah");
        return NEWT;
      }
    }

    void joy_run();
// migrate timnig code to Servo
    int modifier()
    {
      return this->sensitivity * directions();
    }

};

void Joystick::joy_run()
{
  };

#endif
