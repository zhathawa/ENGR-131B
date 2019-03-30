/*
** inspiration for this implementation from Brett Beauregard
** https://github.com/br3ttb/Arduino-PID-Library/
*/

#ifndef _PID_H
#define _PID_H

class PID
{
  private:
    // sampling Frequency
    int _sample_frq;

    int _state;

    // user set pointer
    // in mm
    double _set_point;

    double* _input;
    double _last_output;

    double _error;
    double _sum;

    // gains
    double _kp;
    double _ki;
    double _kd;

    // timing
    unsigned long _current_time;
    unsigned long _last_time;

  public:
    // constructors
    PID()
    {
      set_sample_frq(1000);   // Hz
      set_set_point(155.24);  // mm
      set_gains(1, 1, 1);     // gotta mess with this
      _state = OFF;
      _current_time = millis();
      _last_time = -5.;
      _last_output = 0.;
      _error = 0.;
    };

    PID(int sp, double kp, double ki, double kd)
    {
      set_sample_frq(1000);
      set_set_point(sp);
      set_gains(kp, ki, kd);
      _state = OFF;
      _current_time = millis();
      _last_time = -5.;
      _last_output = 0.;
      _error = 0.;
    };

    // destructors
    ~PID() {};

    // getters / setters
    void set_sample_frq(int frq) { this->_sample_frq = frq; }
    int  get_sample_frq()        { return this->_sample_frq; }

    void set_state(int state) { this->_state = state; }
    int  get_state()          { return this->_state; }

    void set_set_point(int sp) { this->_set_point = sp; }
    int  get_set_point()       { return this->_set_point; }

    void set_kp(double kp) { this->_kp = kp; }
    void set_ki(double ki) { this->_ki = ki; }
    void set_kd(double kd) { this->_kd = kd; }
    void set_gains(double kp, double ki, double kd) {
      set_kp(kp);
      set_ki(ki);
      set_kd(kd);
    }

    double get_kp() { return this->_kp; }
    double get_ki() { return this->_ki; }
    double get_kd() { return this->_kd; }

    unsigned long get_last_time() { return this->_last_time; }

    // magic pid code
    void start()
    {
      // don't run the motor if we don't have to
      if (_state == OFF)
        return;

        // where are we relative to the set point?
        _error = _set_point - *(_input);



    }

};

#endif
