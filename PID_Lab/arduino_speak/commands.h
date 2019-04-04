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
    Serial.println("Your MATLAB has been hacked by ENGR131B!");
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
        Serial.print("Provided frequency was below 1. Frequency set to 1.");
      }
      else if (frq > 1000)
      {
        frq = 1000;
        Serial.print("Provided frequency was above 1000. Frequency set to 1000.");
      }

      // actually set options
      ardy.set_pgen_frq(frq);
      Serial.println("Frequency Set");
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

    option = strtok(NULL, " ");
    cmds->func = "MAN";

    if (strncmp(option, "SET", b2chk) == 0)
    {

      option = strtok(NULL, " ");

      int sensitivity = atoi(option);
      if (sensitivity < 1)
      {
        Serial.print("Sensitivity was below acceptable value of 1. Sensitivity set to 1.");
        sensitivity = 1;
      }
      else if (sensitivity > 10)
      {
        Serial.print("Sensitivity was above acceptable value of 10. Sensitivity set to 10.");
        sensitivity = 10;
      }

      ardy.set_joy_sense(sensitivity);
      Serial.println("Sensitivity Set.");
    }
    else if (strncmp(option, "ON", 2) == 0)
    {
      Serial.println("Manual Control Engaged!");
      ardy.set_joy_state(ON);
    }
    else if (strncmp(option, "OFF", b2chk) == 0)
    {
      Serial.println("Manual Control Disengaged.");
      ardy.set_joy_state(OFF);
    }

    return;
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
          Serial.print("Provided angle was below 0. Angle set to 0.");
        }
        else if (angle > 180)
        {
          angle = 180;
          Serial.print("Provided angle was above 180. Angle set to 180.");
        }

        // actually set options
        ardy.set_lever_ang(angle);
        Serial.println("Servo Moving.");
        cmds->cmd = "SET";
        cmds->opt = option;

        return;
      }
  }

  // ultrasound
  else if (strncmp(option, "ULT", b2chk) == 0)
  {
    // inform the user
  	if (option[3] == '?')
  	{
  		ardy.get_ultra().info();
  	}
  }

  // PID info
  else if (strncmp(option, "CON", b2chk) == 0)
  {
	// Fantastic tag-line
    //Serial.println("You've Ventured Too Far, Padawan. Go Back To Safety.");
    if (option[3] == '?')
    {
      int state = ardy.con_get_state();
      Serial.print("State: ");
      Serial.println(state);
    }
  	// get the next block
  	option = strtok(NULL, ":");

  	// the logic is based on the length of the string
  	// P?, I?, D?
  	if (strlen(option) == 2 && option[1] == '?')
  	{
      float kp = ardy.con_get_kp();
      float ki = ardy.con_get_ki();
      float kd = ardy.con_get_kd();
      int z = ardy.con_get_za();
      Serial.print("P: ");
      Serial.print(kp);
      Serial.print(" || ");
      Serial.print("I: ");
      Serial.print(ki);
      Serial.print(" || ");
      Serial.print("D: ");
      Serial.print(kd);
      Serial.print(" || ");
      Serial.print("ZeroAngle: ");
      Serial.println(z);
  		return;
  	}

  	char* set = strtok(NULL, " ");
  	char* set_val = strtok(NULL, " ");

  	// make sure that we actually have what we think we have
  	if (strncmp(option, "SET", 3) == 0)
  	{
  		if (strncmp(set, "P", 1) == 0)
  		{
        float kp = atof(set_val);
        ardy.con_set_kp(kp);
        Serial.println("kp value set.");

  		}
  		else if (strncmp(set, "I", 1) == 0)
  		{
        float ki = atof(set_val);
        ardy.con_set_ki(ki);
        Serial.println("ki value set.");
  		}
  		else if (strncmp(set, "D", 1) == 0)
  		{
        float kd = atof(set_val);
        ardy.con_set_kd(kd);
        Serial.println("kd value set.");
  		}
      else if (strncmp(set, "Z", 1) == 0)
      {
        int za = atoi(set_val);
        ardy.con_set_za(za);
        Serial.println("ZeroAngle Set");
      }
  		else
  		{
  			Serial.println("Please pass a valid control option. (P, I, or D)");
  			return;
  		}
  	}
  	else if (strncmp(option, "ON", 2) == 0)
    {
      ardy.con_set_state(ON);
      Serial.println("PID Control Engaged");
    }
    else if (strncmp(option, "OFF", 3) == 0)
    {
      ardy.con_set_state(OFF);
      Serial.println("PID Control Disengaged");
    }

  }

  // default
  else
  {
    Serial.println("Please provide a valid command.");
  }
}

#endif
