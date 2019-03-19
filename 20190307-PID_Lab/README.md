# The PID Lab
## ENGR 131B Spr 2019

The goal of the lab is to teach students certain aspects of control by implementing a balancing ball and an Arduino to MatLAB interface. For the Arduino, we are implementing a halfway SCPI version of talking via ASCII strings.

The Arduino will have functions as follows:
- Identification (\*IDN?)
  - The Arduino will return the model and/or a message that this is an Arduino

- Pulse Generator (:PUL:<n>), where <n> is:
  - ?
    - current state of pulse generator (ON or OFF)
  - SET: and some integer number [1, 1000]
    - create digital pulse between 1 and 1000 Hz on pin D2
  - OFF
    - turn pulse generator off


- Manual Joystick Mode (:MAN:<n>), where <n> is:
  - ?
    - current state of Joystick (ON or OFF)
  - SET: and some integer number [1, 10]
      - set sensitivity of joystick
  - ON
    - turn joystick on
  - OFF
    - turn joystick off

- Angle of Servo (:ANG:<n>), where <n> is:
  - ?
    - current angle of servo (integer)
  - SET: and some integer number [1, 90] degrees *tentative*
      - set angle of servo

- Distance of Ultrasound (:ULT:<n>), where <n> is:
  - ?
    - current time value of ultrasound sensor (float)

- Control of PID (:CON:<pid>), where <pid> is P, I, or D:
  - P:<n> (Proportional Query/Control), and <n> is:
    - ?
      - Current value
    - SET: and some float up to 3 point decimal *maybe can't remember*
  - I:<n> (Integral)
  - D:<n> (Derivative)
