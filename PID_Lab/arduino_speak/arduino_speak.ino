
#include "ardy.h"
#include "commands.h"
#include "joystick.h"
#include "pulse_gen.h"
#include "ultra.h"
#include "states.h"

// pointer for commands
char* options;

// chars read from serial line
int charsRead;

// serial message stored here
char msg[50];

// main interface with our various functions
Ardy ardy;

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

  // we can do things
  /*
  ** Just takes up time
  ** TO DO: Remove from code
  if (cmds.func == "PUL")
=======
  if (strncmp(cmds.func, "PUL", 3) == 0) //cmds.func == "PUL")
>>>>>>> 6d0b84dccfed66761b8bec75489e9c4b558f4df4
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
  //ardy.pid_run();
  
  else if (strncmp(cmds.func, "MAN", 3) == 0)
  {
    if (ardy.get_joy_state() == ON)
    {
      ardy.joy_run();
    }
  }

}
