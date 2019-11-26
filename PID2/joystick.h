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

    int last_modifier;

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
      Serial.print(" || ");
      Serial.print("Sensitivity: ");
      Serial.println(this->sensitivity);
    }

    int directions()
    {
      // update voltage
      int val = analogRead(A0);

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


// migrate timnig code to Servo
    int modifier()
    {
      return this->sensitivity * directions();
    }

    int joy_run(int servoAngle) {
      int modifier = this->modifier();
      Serial.print("Modifier: ");
      Serial.println(modifier);
      if (this->last_modifier != modifier) {
        this->last_modifier = modifier;
      }

      if (modifier == NEWT) {
        return servoAngle;
      }

      Serial.print("Servo Angle: ");
      Serial.println(servoAngle);
      return servoAngle + modifier;
    }
};

#endif
