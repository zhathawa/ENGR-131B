#ifndef COMMANDS_H
#define COMMANDS_H

#include "ardy.h"

extern Ardy ardy;

struct commands
{
  // mode optional
  char* mode;

  // non-optional
  char* func;
  char* cmd;
  char* opt;
  
} cmds;

void init_commands(struct commands *cmds)
{
  cmds->mode = NULL;
  cmds->func = NULL;
  cmds->cmd  = NULL;
  cmds->opt  = NULL;
}

template <class generic_object>
void check_info(generic_object obj)
{
  Serial.write(obj.get_state());
}

void set_commands(struct commands *cmds, char *option, int count)
{
  // bytes to check in strncmp
  int b2chk = 3;
  int qByte = 1;
  
  // just check out info
  if (strcmp(option, "*IDN?") == 0)
  {
    // we can update this with whatever we want?
    // would probably be better to move the info we actually want
    // to return to the ardy.h file
    Serial.write("This is an Arduino Uno knock off.\n");
  }

  // pulse generator
  else if (strncmp(option, "PUL", b2chk) == 0)
  {
    /*
    if (strncmp(option[3], "?", qByte) == 0)
    {
      check_info(ardy.get_pgen());
      return;
    }*/
    ardy.get_pgen().set_frequency(2);
    ardy.get_pgen().start_pulse();
    delay(10000);
    ardy.get_pgen().stop_pulse();
  }

  // manual mode
  else if (strncmp(option, "MAN", b2chk) == 0)
  {
    if (strncmp(option[3], "?", qByte) == 0)
    {
      check_info(ardy.get_joystick());
      return;
    }
    
  }

  // servo
  else if (strncmp(option, "ANG", b2chk) == 0)
  {
    
  }

  // ultrasound
  else if (strncmp(option, "ULT", b2chk) == 0)
  {
    
  }

  // PID info
  else if (strncmp(option, "CON", b2chk) == 0)
  {
    
  }

  // default
  else
  {
    Serial.write("Please provide a valid command.\n");
  }
}

#endif
