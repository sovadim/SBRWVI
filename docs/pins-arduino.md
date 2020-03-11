# PINS arduino

This document describes the assignment of pins to arduino Mega in the SBRWVI project

### Component - head

**Yaw:**

`33` - INPUT_A</br>
`31` - INPUT_B</br>
`29` - ENABLE</br>

**Pitch:**

`8` - INPUT 1</br>
`9` - INPUT 2</br>
`10` - INPUT 3</br>
`11` - INPUT 4</br>

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

`19` - PHASE A (int)</br>

**Right wheel encoder:**

`18` - PHASE A (int)</br>

### Component - hands

**Shoulders:**

`39` - left servo</br>
`41` - right servo</br>

**Left forearm:**

`42` - INPUT_A</br>
`44` - INPUT_B</br>
`46` - ENABLE</br>

**Right forearm:**

`53` - INPUT_A</br>
`51` - INPUT_B</br>
`49` - ENABLE</br>

**Left wrist:**

`25` - INPUT_A</br>
`27` - INPUT_B</br>
`23` - ENABLE</br>

**Right wrist:**

`52` - INPUT_A</br>
`50` - INPUT_B</br>
`48` - ENABLE</br>

### Component - MPU-6050

`3.3V` - VCC</br>
`GND` - GND</br>
`20` - SDA</br>
`21` - SCL</br>
