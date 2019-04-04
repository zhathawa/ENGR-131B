#ifndef ARDY_H
#define ARDY_H

#include "joystick.h"
#include "lever.h"
// #include "PID_v1.h"
#include "pulse_gen.h"
#include "ultra.h"
#include "pidv2.h"


class Ardy
{
  private:
    // TODO: PIN Tracking

    // TODO: State tracking

    // handy dandy variables
    int _last_modifier;
    // long _start_time;
    // long _current_time;
    // long _elapsed_time;
  //
	// double kp;
	// double ki;
	// double kd;

    // objects
    Joystick joy;
    Lever lever;
	// PID pid;
    PulseGenerator pgen;
    Ultrasonic ultra;
    PID pid;

  public:
    Ardy()
    {
    //   _last_modifier = -5;
    //   _start_time = 0;
    //   _elapsed_time = 0;
    //   _current_time = 0;
	  // kp = 0.;
	  // ki = 0.;
	  // kd = 0.;
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

    // :CON functions
    PID get_pid() { return this->pid; }

    float con_get_kp() {return this->pid.get_kp(); }
    void con_set_kp(float kp) { this->pid.set_kp(kp); }

    float con_get_ki() {return this->pid.get_ki(); }
    void con_set_ki(float ki) { this->pid.set_ki(ki); }

    float con_get_kd() {return this->pid.get_kd(); }
    void con_set_kd(float kd) { this->pid.set_kd(kd); }

    int con_get_za() {return this->pid.get_zero_angle(); }
    void con_set_za(int za) { this->pid.set_zero_angle(za); }

    int con_get_state() { return this->pid.get_state(); }
    void con_set_state(int state) { this->pid.set_state(state); }

    int con_get_duration() { return this->pid.get_set_duration(); }
    void con_set_duration(int duration) { this->pid.set_set_duration(duration); }

    void con_start_pid() { this->pid.ball_control(); }
    int con_get_servo() { return this->pid.get_servo(); }

    // defined below
	// gonna clean up file structur should we have time
    void pid_run();
    void joy_run();

    void magic_change();
    void magic_move();
};

// void Ardy::magic_change() {};
// void Ardy::magic_move()   {};

void Ardy::joy_run()
{
  int modifier = Ardy::get_joy_mod();
  if (_last_modifier != modifier)
  {
    _last_modifier = modifier;
  }

  if (modifier == NEWT)
    return;

  int ang = Ardy::get_lever_ang();
  Ardy::set_lever_ang(ang + modifier);

}

// void Ardy::pid_run()
// {
//   // run without delay
//   // get the current time
//   _current_time = millis();
//
//   // if the elapsed time is above threshhold delay,
//   // then we can update the servo
//   if (_current_time - _start_time >= 150)
//   {
//     /*
//     ** 1) Calculate distance to ball
//     ** 2) Use distance to calculate the appropiate dTheta / speed
//     ** 3) Move the arm appropriately
//     ** 4) Update the _current_time
//     */
//
//     // first update the distance
//     this->ultra.start();
//
//     // magic
//     magic_change();
//     magic_move();
//
//     // update the start_time
//     _start_time = _current_time;
//   }
//
//   return;
// }

#endif
