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
  Serial.print("State:\n");
  Serial.print(obj.get_state());
  Serial.print("\n");
  Serial.print("Frequency:\n");
  Serial.print(obj.get_frequency());
  Serial.print("\n");
}

void set_commands(struct commands *cmds, char *msg)
{
  // bytes to check in strncmp
  int b2chk = 3;
  int qByte = 1;

  char* option = strtok(msg, ": ");
  
  // just check out info
  if (strcmp(option, "*IDN?") == 0)
  {
    // we can update this with whatever we want?
    // would probably be better to move the info we actually want
    // to return to the ardy.h file
    Serial.write("This is an Arduino Uno knock off.\n");
    cmds->mode = "*IDN?";
  }

  // pulse generator
  else if (strncmp(option, "PUL", b2chk) == 0)
  {
    cmds->mode = "PUL";
    if (option[3] == '?')
    {
      check_info(ardy.get_pgen());
      cmds->func = "?";
      return;
    }
    else //if (option[3] == ':')
    {
      option = strtok(NULL, " ");
      // SET N for setting the frequency lims [1, 1000]
      if (strncmp(option, "SET", b2chk) == 0)
      {
        cmds->func = "SET";
        
        // get next token
        option = strtok(NULL, " ");

        // make sure we have an integer
        int frq = atoi(option);

        // set frequency
        ardy.set_pgen_frq(frq);
        
        return;
      }
      // ON for turning pulse generator on
      if (strncmp(option, "ON", 2) == 0)
      {
        // set stuff
        ardy.set_pgen_state(ON);

        // inform user
        Serial.println("Pulse ON\n");

        // TO DO: actually turn on pulse generator
        // make sure frequency > 0 first
        // inform user if it isn't
        
        return;
      }
      // OFF for turning pulse generator off
      if (strncmp(option, "OFF", b2chk) == 0)
      {
        ardy.set_pgen_state(OFF);
        Serial.write("Pulse OFF\n");

        // TO DO: turn pulse off
        
        return;
      }
    }
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
