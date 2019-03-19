#define err(msg, errno) { Serial.println("%s", msg); return errno };

// pointers for commands
char* mode;
char* cmd;
char* opt;

// various things
int int_arg;
int count = 1;
int charsRead;

float flt_arg;

char msg[50];

void setup() {
  mode = malloc(sizeof(char) * 4);
  if (mode == NULL)
	err("Could not allocate memory for mode", NULL);

  cmd = malloc(sizeof(char) * 4);
  if (cmd == NULL)
	err("Could not allocate memory for cmd", NULL);

  opt = malloc(sizeof(char) * 4);
  if (opt == NULL)
	err("Could not allocate memory for opt", NULL);

  Serial.begin(115200);
}


void loop() {

  // check that we have things to read
  if(Serial.available())
  {
    chars = Serial.readBytesUntil('\n', msg, sizeof(msg) - 1);
    msg[chars] = '\0';
	
    int limit = strlen(msg);

	char* fn= malloc(sizeof(char)*4);
	fn = strncpy(fn, &fn[1], 4);
  }
	

  // cleanup
  freeArgs();
}


void* grabInput(char* msg, int position)
{
	: 
}

void* freeArgs()
{
	free(mode);
	free(cmd);
	free(opt);
}
