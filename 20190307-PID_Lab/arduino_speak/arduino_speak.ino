

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

PulseGenerator pgen;

void setup() {
  init_commands(&cmds);
  pgen.set_frequency(2);
  pinMode(13, OUTPUT);
  Serial.begin(115200);
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


    grab first token
   options = strtok(msg, ":");

   while (options != NULL)
   {
     set_commands(&cmds, options);
     // Serial.write(options);
     // digitalWrite(13, HIGH);
     // delay(1000);
     // digitalWrite(13, LOW);
     // delay(1000);
     // digitalWrite(13, HIGH);
     // options = strtok(NULL, ":");
     //count++;
     //set_commands(options, count);
   }
  }

  delay(100);
}
