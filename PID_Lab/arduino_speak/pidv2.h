#ifndef PIDV2_H
#define PIDV2_H

#include "states.h"
#include "ultra.h"

class PID
{
  private:
    // Ultrasonic
    Ultrasonic ultra;

    // Control variables
    long duration;
    float PID_error;
    float previous_error;
    float elapsedTime, Time, timePrev;
    float PID_value;
    int servo_output;
    int set_duration;
    int last_set_duration;

    int state;
    int zero_angle;

    //PID constants
    //////////////////////////////////////////////////////////
    float kp;   float ki;   float kd;
    //////////////////////////////////////////////////////////

    int PID_p;    int PID_i;    int PID_d;
    float last_kp;
    float last_ki;
    float last_kd;

  public:

    PID()
    {
      this->state = OFF;
      this->zero_angle = 130;
      this->servo_output = 100;

      this->PID_error = 0;
      this->previous_error = 0;
      this->PID_value = 0;
      this->set_duration = 600;
      this->last_set_duration = 0;

      this->kp = 50;
      this->ki = 0;
      this->kd = 0;

      this->PID_p = 0;
      this->PID_i = 0;
      this->PID_d = 0;

      this->last_kp = 0;
      this->last_ki = 0;
      this->last_kd = 0;

    };

    ~PID() {};

    int get_state() { return this->state; }
    void set_state(int state) { this->state = state; }

    int get_zero_angle() { return this->zero_angle; }
    void set_zero_angle(int zero_angle) { this->zero_angle = zero_angle; }

    float get_kp() { return this->kp; }
    void set_kp(float kp) { this->kp = kp; }

    float get_ki() { return this->ki; }
    void set_ki(float ki) { this->ki = ki; }

    float get_kd() { return this->kd; }
    void set_kd(float kd) { this->kd = kd; }

    int get_set_duration() { return this->set_duration; }
    void set_set_duration(int set_duration) { this->set_duration = set_duration; }

    int get_servo() { return this->servo_output; }

    void ball_control()
    {
      // if (this->state = OFF)
      //   return;

      this->ultra.start();
      this->duration = this->ultra.get_duration();
      // Serial.print(this->duration);
      // Serial.print(" :: ");

      this->PID_error = this->set_duration - this->duration;
      // Calulate P
      this->PID_p = 0.01*this->kp*this->PID_error;
      // Calculate I
      this->PID_i = 0.01*this->PID_i + (this->ki * this->PID_error);

      // Calculate D
      this->timePrev = this->Time;
      this->Time = millis();
      this->elapsedTime = (this->Time - this->timePrev) / 1000;
      this->PID_d = 0.01*this->kd*((this->PID_error - this->previous_error)/this->elapsedTime);

      this->PID_value = this->PID_p + this->PID_i + this->PID_d;
      if (this->PID_value > 180 - this->zero_angle) { this->PID_value = 180 - this->zero_angle; }
      if (this->PID_value < -this->zero_angle) { this->PID_value = -this->zero_angle; }

      // Serial.print(this->PID_value);
      // Serial.print(" :: ");

      this->servo_output = this->zero_angle + this->PID_value;
      // Serial.println(this->servo_output);

      // lever.write(this->servo_output);
      this->previous_error = this->PID_error;
    }

};

#endif
