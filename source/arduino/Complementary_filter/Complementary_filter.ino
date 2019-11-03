#include <Wire.h>

const int MPU_addr = 0x68;

int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
double AcYsum, GyXsum;

// смещение нуля баланса.
double balancing_zerro=2.4;

void setup()
{
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  // Производим запись в регистр энергосбережения MPU-6050 .
  Wire.write(0x6B);
  Wire.write(0);
  // устанавливаем его в ноль.
  Wire.endTransmission(true);
  Serial.begin(9600);
  //_stop();
  AcYsum = 0;
  GyXsum = 0;
  
  //Serial.println(compensatorX);
}

// Основная программа.
void loop()
{
  debug();
  //complementary_filter();
}

void debug()
{
  while(true)
  {
    Wire.beginTransmission(MPU_addr);
    Wire.write(0x3B);

    Wire.endTransmission(false);
    Wire.requestFrom(MPU_addr, 14, true);
    
    // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
    AcX = Wire.read() << 8 | Wire.read();
    // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
    AcY = Wire.read() << 8 | Wire.read();
    // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
    AcZ = Wire.read() << 8 | Wire.read();
    // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
    Tmp = Wire.read() << 8 | Wire.read();
    // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
    GyX = Wire.read() << 8 | Wire.read();
    // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
    GyY = Wire.read() << 8 | Wire.read();
    // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
    GyZ = Wire.read() << 8 | Wire.read();

    Serial.print("AcX: ");
    Serial.print(AcX);
    Serial.print(" / AcY: ");
    Serial.print(AcY);
    Serial.print(" / AcZ: ");
    Serial.print(AcZ);

    Serial.print("|| GyX: ");
    Serial.print(GyX);
    Serial.print(" / GyY: ");
    Serial.print(GyY);
    Serial.print(" / GyZ: ");
    Serial.print(GyZ);

    Serial.println("\n-----");

    delay(100);
  }
}

void complementary_filter()
{
  uint32_t timer = micros();
  while (true)
  {    
    Wire.beginTransmission(MPU_addr);
    Wire.write(0x3B);
    
    // Готовим для чтения регистры с адреса 0x3B.
    Wire.endTransmission(false);
    // Запрос 14 регистров.
    Wire.requestFrom(MPU_addr, 14, true);
    // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
    AcX = Wire.read() << 8 | Wire.read();
    // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
    AcY = Wire.read() << 8 | Wire.read();
    // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
    AcZ = Wire.read() << 8 | Wire.read();
    // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
    Tmp = Wire.read() << 8 | Wire.read();
    // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
    GyX = Wire.read() << 8 | Wire.read();
    // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
    GyY = Wire.read() << 8 | Wire.read();
    // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
    GyZ = Wire.read() << 8 | Wire.read();
    
    // Расчет угла по показаниям акселерометра
    // с учетом корректировки точки равновесия balancing_zerro.
    AcYsum = (atan2(AcY, AcZ)) * RAD_TO_DEG+balancing_zerro;
    
    // Измерение наклона по Х.
    // Использование Комплементарного фильтра,
    // alfa - коэффициент фильтра.
    double alfa = 0.001;
    GyXsum = (1 - alfa) * (GyXsum + ((double)GyX * (double)(micros() - timer)) / 131000000.0) + alfa * AcYsum;
    
    // Для перевода угловой скорости в угол нужно знать время!
    timer = micros();
    delay(500);
    Serial.println(GyXsum);
  }
}
