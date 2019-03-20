#ifndef COMMANDS_H
#define COMMANDS_H

struct commands
{
  // mode optional
  char* mode;

  // non-optional
  char* func;
  char* cmd;
  char* opt;
};

void init_commands(struct commands *cmds)
{
  cmds->mode = NULL;
  cmds->func = NULL;
  cmds->cmd  = NULL;
  cmds->opt  = NULL;
}

void set_commands(struct commands *cmds, char *option, int count)
{
  if (strcmp(option, "*IDN?") == 0)
  {
    Serial.write("This is an Arduino Uno knock off.\n");
  }
  else if (strncmp(option, "PUL", 3) == 0)
  {
  }
}

#endif
