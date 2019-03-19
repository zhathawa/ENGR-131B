// pointer for commands
char* options;

// various things
int int_arg;
int count = 0;
int charsRead;

float flt_arg;

char msg[50];

struct commands
{
  // mode optional
  char* mode;

  // non-optional
  char* func;
  char* cmd;
  char* opt;
};

struct commands cmds;

void setup() {
  init_commands();
  Serial.begin(115200);
}


void loop() {

  // check that we have things to read
  if(Serial.available())
  {
    // read from serial port
    charsRead = Serial.readBytesUntil('\n', msg, sizeof(msg) - 1);

    // make c string
    msg[charsRead] = '\0';

    // tokenize
    options = strtok(msg, ":");
    while (options != NULL)
    {
      count++;
      set_commands(options, count);
    }
  }
}

void init_commands()
{
  cmds.mode = NULL;
  cmds.func = NULL;
  cmds.cmd  = NULL;
  cmds.opt  = NULL;
}

void set_commands(char* option, int count)
{
}

