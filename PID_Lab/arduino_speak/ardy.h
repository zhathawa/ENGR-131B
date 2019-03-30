#ifndef ARDY_H
#define ARDY_H

#include "joystick.h"
#include "pulse_gen.h"
#include "ultra.h"
#include "lever.h"

class Ardy
{
  private:
    // TODO: PIN Tracking

    // TODO: State tracking

    // handy dandy variables
    int _last_modifier;
    long _start_time;
    long _current_time;
    long _elapsed_time;

    // objects
    Joystick joy;
    PulseGenerator pgen;
    Ultrasonic ultra;
    Lever lever;

  public:
    Ardy()
    {
      _last_modifier = -5;
      _start_time = 0;
      _elapsed_time = 0;
      _current_time = 0;
    };

    ~Ardy() {};


    // TODO: JOYSTICK STUFF
    Joystick get_joystick() { return this->joy; }

    void set_joy_state(int state) { this->joy.set_state(state); }
    int get_joy_state() { return this->joy.get_state(); }
    int get_joy_mod() { return this->joy.modifier(); }
    void set_joy_sense(int sensitivity) { this->joy.set_sensitivity(sensitivity); }


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

    Lever get_lever() { return this->lever; }
    void set_lever_ang(int ang) { this->lever.set_ang(ang); }
    int get_lever_ang() { return this->lever.get_ang(); }
    void init_lever() { this->lever.init_attach(); }


    // defined below
	// gonna clean up file structur should we have time
    void pid_run();
    void joy_run();

    void magic_change();
    void magic_move();
};

void Ardy::magic_change() {};
void Ardy::magic_move()   {};

void Ardy::joy_run()
{
  int modifier = Ardy::get_joy_mod();
  if (_last_modifier != modifier)
  {
    Serial.print("Modifier = ");
    Serial.println(modifier);
    _last_modifier = modifier;
  }

  if (modifier == NEWT)
    return;

  int ang = Ardy::get_lever_ang();
  // Serial.println(ang);
  Ardy::set_lever_ang(ang + modifier);
  Serial.println(ang + modifier);

}

void Ardy::pid_run()
{
  // run without delay
  // get the current time
  _current_time = millis();

  // if the elapsed time is above threshhold delay,
  // then we can update the servo
  if (_current_time - _start_time >= 150)
  {
    /*
    ** 1) Calculate distance to ball
    ** 2) Use distance to calculate the appropiate dTheta / speed
    ** 3) Move the arm appropriately
    ** 4) Update the _current_time
    */

    // first update the distance
    this->ultra.start();

    // magic
    magic_change();
    magic_move();

    // update the start_time
    _start_time = _current_time;
  }

  return;
}

#endif
