
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
void setup()
{
  // initialize our commands struct
  init_commands(&cmds);

  // start serial communication
  Serial.begin(115200);

  // give everything time to set up
  delay(500);

  // inform user
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
  if (cmds.func == "PUL")
  {
    // PULSE
    if (ardy.get_pgen().get_state() == ON)
    {
      ardy.pulse();
      return;
    }

  }

}
