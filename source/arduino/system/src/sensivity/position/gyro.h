#pragma once

#include <Wire.h>


class Gyro
{
public:
  explicit Gyro();

  void debug();

private:

  // I2C-address for MPU-6050
  const int MPU_addr = 0x68;

  int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
  
};
