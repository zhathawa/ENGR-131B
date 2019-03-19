# The PID Lab
## ENGR 131B Spr 2019

The goal of the lab is to teach students certain aspects of control by implementing a balancing ball and an Arduino to MatLAB interface. For the Arduino, we are implementing a halfway SCPI version of talking via ASCII strings.

The Arduino will have functions as follows:
- Identification (\*IDN?)
  - The Arduino will return the model and/or a message that this is an Arduino

- Pulse Generator (:PUL:X), where X is:
  - ?
    - current state of pulse generator (ON or OFF)
  - SET:N and N is some integer number [1, 1000]
    - create digital pulse between 1 and 1000 Hz on pin D2
  - OFF
    - turn pulse generator off


- Manual Joystick Mode (:MAN:X), where X is:
  - ?
    - current state of Joystick (ON or OFF)
  - SET:N and N is some integer number [1, 10]
      - set sensitivity of joystick
  - ON
    - turn joystick on
  - OFF
    - turn joystick off

- Angle of Servo (:ANG:X), where X is:
  - ?
    - current angle of servo (integer)
  - SET:N and N is some integer number [1, 90] degrees *tentative*
      - set angle of servo

- Distance of Ultrasound (:ULT:X), where X is:
  - ?
    - current time value of ultrasound sensor (float)

- Control of PID (:CON:X), where X is P, I, or D:
  - P:Y (Proportional Query/Control), and Y is:
    - ?
      - Current value
    - SET: and some float up to 3 point decimal *maybe can't remember*
  - I:X (Integral)
  - D:X (Derivative)

- Examples:
  - Set the pulse generator to 10 Hz and turn it on
    - :PUL:SET:10\n:PUL:ON
  - Return the current D value in PID control
    - :CON:P:?
