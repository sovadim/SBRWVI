# PINS arduino

This document describes the assignment of pins to arduino Mega in the SBRWVI project

### Component - head

IN_YAW_L 33

IN_YAW_R 31

EN_YAW__ 29


IN_PITCH_1 8

IN_PITCH_2 9

IN_PITCH_3 10

IN_PITCH_4 11

### Component - chassis

**Left wheel:**

`47` - INPUT A</br>
`45` - INPUT B</br>
`4`  - ENABLE (pwm)</br>

**Right wheel:**

`26` - INPUT A</br>
`24` - INPUT B</br>
`4`  - ENABLE (pwm)</br>

**Left wheel encoder:**

L_ENC_IN_F 0

L_ENC_IN_B 0

**Right wheel encoder:**

R_ENC_IN_F 0

R_ENC_IN_B 0

### Component - hands

* shoulders

SRV_PIN_L 39

SRV_PIN_R 41

SHOULDERS_START_POS 125

* left forearm

IN_LEFT_EL_L 42

IN_LEFT_EL_R 44

EN_LEFT_EL__ 46

* right forearm

IN_RIGHT_EL_L 53

IN_RIGHT_EL_R 51

EN_RIGHT_EL__ 49

* left wrist

IN_LEFT_WR_L 25

IN_LEFT_WR_R 27

EN_LEFT_WR__ 23

* right wrist

IN_RIGHT_WR_L 52

IN_RIGHT_WR_R 50

EN_RIGHT_WR__ 48

* encoders

ENC_SHLD_LEFT_A 0

ENC_SHLD_LEFT_B 0

ENC_SHLD_RIGHT_A 0

ENC_SHLD_RIGHT_B 0

ENC_WRT_RIGHT_A 0

ENC_WRT_RIGHT_B 0


ENC_YAW_A 0
ENC_YAW_B 0