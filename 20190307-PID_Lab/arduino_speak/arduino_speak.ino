String arg1;
String arg2;
String arg3;
int int_arg;
float flt_arg;
int count = 1;


char msg[50];

void setup() {
  Serial.begin(115200);
}


void loop() {
  char *ptr;
  int chars;
  if(Serial.available())
  {
    chars = Serial.readBytesUntil('\n', msg, sizeof(msg) - 1);
    msg[chars] = '\0';
    ptr = msg;
    int limit = strlen(msg);
    for (int i = 0; i<= limit; i++){
      if (msg[i] == '*'){
        Serial.println(ptr);
        if (strcmp("*IDN?", ptr) == 0){
          Serial.println("Hello, I am your Arduino");
          break;
        }
      } else if (msg[i] == ':'){
          msg[i] = '\0';
          Serial.println(ptr);
          ptr = &msg[i+1];
//          if (strcmp("M", ptr[0]) == 0)) {
            // manual mode
          Serial.println("Your Manual Mode Options Are...");
//          }
      }else{
          Serial.println("TRYING TO MATCH *IDN?");
          Serial.println("Not a valid command!");
          Serial.println(ptr);
          break;
       }
     }
   } 
 }
