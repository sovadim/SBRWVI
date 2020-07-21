# Components

This document describes the components of which the robot is made

**Components list:**

* Platform
* Raspberry pi4
* Arduino Mega2560
* Camera
* Head
* Chassis
* Hands
* MPU
* Power supply system

## Raspberry pi

`Raspberry pi4` is a robot on-board computer. It defines current tasks and sends commands to arduino

## Arduino Mega

`Arduino Mega2560` manages peripherals consisting of motors and MPU

## Camera

Usual webcam is suitable

## Head

The neck is a bunch of two motors. The movement to the left and right is carried out by a motor with a gearbox. The `28BYJ-48 stepper motor with ULN2003 controller` performs a forward and reverse tilt.

The neck holds the platform on which the webcam is installed

An `incremental encoder` mounted at the bottom of the neck determines the angle of rotation

Gear motor connected to arduino via `L293D` driver

## Chassis

The chassis consists of two gear motors `JGA25-370B 12V 1:34 205 rpm` with encoders

Chassis connects to Arduino Mega via `L298N` driver

## Hands

The hands are divided into 3 parts: `shoulders`, `forearms` and `wrists`

The shoulders of the robot are 2 servos `FS5519M`

The forearms and wrists are driven by 4 gear motors

Gear motors connected to arduino via `L293D` drivers

## MPU

The project uses `MPU-6050` to obtain rotation angles and accelerations of the robot, which help the robot keep balance when moving

## Power supply system

The power supply system includes 4 `18650` batteries connected in series, and 3 `dc-dc converters LM2596`

The voltage on the battery pack is from `13 to 17 V`

The first converter produces `15 V` or less from the battery to the chassis, depending on the charge level

The second converter produces `6 V` and powers the gear motors

The third converter produces `5 V` and powers the Arduino Mega and the stepper motor
