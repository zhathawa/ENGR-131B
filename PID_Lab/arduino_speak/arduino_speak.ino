
#include "ardy.h"
#include "commands.h"
#include "joystick.h"
#include "pulse_gen.h"
#include "states.h"
#include "ultra.h"
// #include "PID_v1.h"
#include "pidv2.h"

// pointer for commands
char* options;

// chars read from serial line
int charsRead;

// serial message stored here
char msg[50];

// main interface with our various functions
Ardy ardy;

int sOutput;

// setup
void setup() {
  init_commands(&cmds);
  Serial.begin(115200);
  // do we actually need this delay?
  // I don't think we do.
  delay(500);
  ardy.init_lever();
  Serial.println("Ready!");
}


void loop() {
  // check that we have things to read
  if (Serial.available())
  {
    // read from serial port
    charsRead = Serial.readBytesUntil('\n', msg, sizeof(msg) - 1);

    // make c string
    msg[charsRead] = '\0';

    // parse and set commands up
    set_commands(&cmds, msg);
  }

  if (strncmp(cmds.func, "CON", 3) == 0)
  {
    if (ardy.con_get_state() == ON)
    {
      ardy.con_start_pid();
      sOutput = ardy.con_get_servo();
      // Serial.print("Running:: Next servo angle: ");
      Serial.println(sOutput);
      ardy.set_lever_ang(sOutput);
      delay(150);

    }
  }

  // we can do things
  /*
  ** Just takes up time
  ** TO DO: Remove from code
  if (cmds.func == "PUL")
  if (strncmp(cmds.func, "PUL", 3) == 0) //cmds.func == "PUL")
  {
    // PULSE
    if (ardy.get_pgen().get_state() == ON)
    {
      ardy.pulse();
      return;
    }

  }
  */

  // do some magic
  // ardy.pid_run();
  /*
  else if (strncmp(cmds.func, "MAN", 3) == 0)
  {
    if (ardy.get_joy_state() == ON)
    {
      ardy.joy_run();
    }
  }
  */

}
