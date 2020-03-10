# PINS arduino

This document describes the assignment of pins to arduino Mega in the SBRWVI project

### Component - head

**Yaw:**

IN_YAW_L 33</br>
IN_YAW_R 31</br>
EN_YAW__ 29</br>

**Pitch:**

IN_PITCH_1 8</br>
IN_PITCH_2 9</br>
IN_PITCH_3 10</br>
IN_PITCH_4 11</br>

### Component - chassis

**Left wheel:**

`47` - INPUT A</br>
`45` - INPUT B</br>
`5` - ENABLE (pwm)</br>

**Right wheel:**

`26` - INPUT A</br>
`24` - INPUT B</br>
`4` - ENABLE (pwm)</br>

**Left wheel encoder:**

L_ENC_IN_F 0</br>
L_ENC_IN_B 0</br>

**Right wheel encoder:**

R_ENC_IN_F 0</br>
R_ENC_IN_B 0</br>

### Component - hands

**Shoulders:**

`39` - left servo</br>
`41` - right servo</br>

**Left forearm:**

IN_LEFT_EL_L 42</br>
IN_LEFT_EL_R 44</br>
EN_LEFT_EL__ 46</br>

**Right forearm:**

IN_RIGHT_EL_L 53</br>
IN_RIGHT_EL_R 51</br>
EN_RIGHT_EL__ 49</br>

**Left wrist:**

IN_LEFT_WR_L 25</br>
IN_LEFT_WR_R 27</br>
EN_LEFT_WR__ 23</br>

**Right wrist:**

IN_RIGHT_WR_L 52</br>
IN_RIGHT_WR_R 50</br>
EN_RIGHT_WR__ 48</br>

### Component - MPU-6050

`3.3V` - VCC</br>
`GND` - GND</br>
`20` - SDA</br>
`21` - SCL</br>
