# The PID Lab
## ENGR 131B Spr 2019

The goal of the lab is to teach students certain aspects of control by implementing a balancing ball and an Arduino to MatLAB interface. For the Arduino, we are implementing a halfway SCPI version of talking via ASCII strings.

The Arduino will have functions as follows:
- Identification (\*IDN?)
  - The Arduino will return the model and/or a message that this is an Arduino

- Pulse Generator (:PULX), where X is:
  - ?
    - current state of pulse generator (ON or OFF)
  - :SET N and N is some integer number [1, 1000]
    - create digital pulse between 1 and 1000 Hz on pin D2
  - :OFF
    - turn pulse generator off
  - :ON
    - turn pulse generator on


- Manual Joystick Mode (:MANX), where X is:
  - ?
    - current state of Joystick (ON or OFF)
  - :SET N and N is some integer number [1, 10]
      - set sensitivity of joystick
  - :ON
    - turn joystick on
  - :OFF
    - turn joystick off

- Angle of Servo (:ANGX), where X is:
  - ?
    - current angle of servo (integer)
  - :SET N and N is some integer number [1, 90] degrees *tentative*
      - set angle of servo

- Distance of Ultrasound (:ULTX), where X is:
  - ?
    - current time value of ultrasound sensor (float)

- Control of PID (:CON:X), where X is P, I, or D:
  - :PY (Proportional Query/Control), and Y is:
    - ?
      - Current value
    - :SET N and N is some float up to 3 point decimal *maybe can't remember*
  - IY (Integral), and Y is the same arguments as above
  - DY (Derivative), and Y is the same arguments as above

- Examples:
  - Set the pulse generator to 10 Hz and turn it on
    - :PUL:SET 10
    - :PUL:ON
  - Return the current P, I, and D values in PID control
    - :CON:P?
    - :CON:I?
    - :CON:D?
  - Set the P Value to 14.607
    - :CON:P:SET 14.607
