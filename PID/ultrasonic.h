#ifndef ULTRA_H
#define ULTRA_H

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class Ultrasonic {
  private:
    // echo is what is we measure
    // trigger is what we send to the ultrasonic
    int echo, trigger;
    float duration;
    float current_distance;
    
  public:
    Ultrasonic();
    Ultrasonic(int, int);
    
    ~Ultrasonic();

    int getEcho();
    void setEcho(int);
    int getTrigger();
    void setTrigger(int);

    float getDuration();
    void setDuration(float);

    float getCurrentDistance();
    void setCurrentDistance(float);
    
    float calcDistance();
};

#endif
