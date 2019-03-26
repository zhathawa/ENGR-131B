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
    cmds->func = "*IDN?";
  }

  // pulse generator
  else if (strncmp(option, "PUL", b2chk) == 0)
  {
    cmds->func = "PUL";
    if (option[3] == '?')
    {
      //check_info(ardy.get_pgen());
      ardy.get_pgen().info();
      cmds->cmd = "?";
      return;
    }

    option = strtok(NULL, " ");

    // SET N for setting the frequency lims [1, 1000]
    if (strncmp(option, "SET", b2chk) == 0)
    {
      // get frequency value
      option = strtok(NULL, " ");

      // make sure we have an integer
      int frq = atoi(option);

      // check frequency is appropriate
      // TODO: come up with wittier output for inappropriate frequencies
      if (frq < 1)
      {
        frq = 1;
        Serial.write("Provided frequency was below 1. Frequency set to 1.");
      }
      else if (frq > 1000)
      {
        frq = 1000;
        Serial.print("Provided frequency was above 1000. Frequency set to 1000.");
      }

      // actually set options
      ardy.set_pgen_frq(frq);
      cmds->cmd = "SET";
      cmds->opt = option;

      return;
    }

    // ON for turning pulse generator on
    if (strncmp(option, "ON", 2) == 0)
    {
      // set stuff
      ardy.set_pgen_state(ON);
      cmds->cmd = "ON";

      // inform user
      // might want to take this out
      // because I think we're going to have to drive
      // the pin from the main arduino loop
      Serial.println("Pulse ON");

      return;
    }

    // OFF for turning pulse generator off
    if (strncmp(option, "OFF", b2chk) == 0)
    {
      ardy.set_pgen_state(OFF);

      // remove, same as info in pulse on section
      Serial.println("Pulse OFF");

      return;
    }
  }

  // manual mode
  else if (strncmp(option, "MAN", b2chk) == 0)
  {
    if (option[3] == '?')
    {
      //check_info(ardy.get_joystick());
      ardy.get_joystick().info();
      return;
    }
  }

  // servo
  else if (strncmp(option, "ANG", b2chk) == 0)
  {
      if (option[3] == '?')
      {
        Serial.println(ardy.get_lever_ang());
        return;
      }

      option = strtok(NULL, " ");

      // SET N for setting the frequency lims [1, 1000]
      if (strncmp(option, "SET", b2chk) == 0)
      {
        // get frequency value
        option = strtok(NULL, " ");

        // make sure we have an integer
        int angle = atoi(option);
        Serial.println(angle);

        // check frequency is appropriate
        // TODO: come up with wittier output for inappropriate frequencies
        if (angle < 0)
        {
          angle = 0;
          Serial.write("Provided angle was below 0. Angle set to 0.");
        }
        else if (angle > 180)
        {
          angle = 180;
          Serial.print("Provided angle was above 180. Angle set to 180.");
        }

        // actually set options
        ardy.set_lever_ang(angle);
        cmds->cmd = "SET";
        cmds->opt = option;

        return;
      }
  }

  // ultrasound
  else if (strncmp(option, "ULT", b2chk) == 0)
  {
  	if (option[3] == '?')
  	{
  		ardy.get_ultra().info();
  	}
  }

  // PID info
  else if (strncmp(option, "CON", b2chk) == 0)
  {

  }

  // default
  else
  {
    Serial.write("Please provide a valid command.\n");
    //Serial.println(option);
  }
}

#endif
