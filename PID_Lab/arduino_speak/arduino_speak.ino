

#include "commands.h"
#include "pulse_gen.h"
#include "states.h"

// pointer for commands
char* options;

// various things
int int_arg;
int count = 0;
int charsRead;
float flt_arg;

char msg[50];

Ardy ardy;

void setup() {
  init_commands(&cmds);
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  delay(500);
  Serial.write("Ready!\n");
}


void loop() {

    //pgen.high_pulse();
    //pgen.low_pulse();
    //delay(1000);
// check that we have things to read
 if(Serial.available())
 {
   // read from serial port
   charsRead = Serial.readBytesUntil('\n', msg, sizeof(msg) - 1);

   // make c string
   msg[charsRead] = '\0';

   // grab first token
   //options = strtok(msg, ":");
   set_commands(&cmds, msg);
   
   /*
   while (options != NULL)
   {
     set_commands(&cmds, options);
     options = strtok(NULL, ":");
   }
   */
  }

  delay(100);
}
