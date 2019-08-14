#include "Kalman.h"
// Библиотека для работы с протоколом I2C (порты A5/SCL и A4/SDA)
#include <Wire.h>
// упрощенный I2C-адрес нашего гироскопа/акселерометра MPU-6050 .
const int MPU_addr = 0x68;
// Переменные для хранения данных, возвращаемых прибором.
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
long AcYsum, GyXsum;
// Переменные для хранения состояния двух моторов.
int motor_L1, motor_L2;
int motor_R1, motor_R2;
int s_diod = 5;
// Переменные для хранения данных времени работы контроллера Arduino.
unsigned long time_data_request, time_in_system;
// Время, через которое производится опрос гироскопа/акселерометра .
const unsigned long time_step = 10;
uint32_t timer;
double accXangle; // Угол, посчитанный по акселерометру.
double gyroXangle ; // Угол, посчитанный по гироскопу.
double gyroXrate; // Приращение угла по показаниям гироскопа.
// Результирующий угол после обработки фильтром Калмана.
double kalAngleX ;
Kalman kalmanX;
Kalman kalmanY;

void _stop();
void forward();
void backward();

//===========================================================

void setup()
{
  // Коэффициенты для фильтра Калмана.
  kalmanX.setQangle(0.001);
  kalmanX.setQbias(0.003);
  kalmanX.setRmeasure(0.03);
  // Заносим в переменные номера контактов (пинов) Arduino.
  // Для левых и правых моторов машинки.
  //setup_motor_system(3, 4, 7, 8);
  // Двигатели остановлены.
  _stop();
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  // Запись в регистр энергосбережения MPU-6050 .
  Wire.write(0x6B);
  Wire.write(0);
  // установить его в ноль
  Wire.endTransmission(true);
  Serial.begin(9600);
  pinMode(s_diod, OUTPUT);
  digitalWrite(s_diod, LOW);
  delay(200);
  digitalWrite(s_diod, HIGH);
  _stop();
  kalmanX.setAngle(0); // Начальные углы.
  kalmanY.setAngle(0);
  timer = micros();
}

//====================================================================

void loop()
{
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
    
    // Расчет угла по показаниям акселерометра .
    accXangle = (atan2(AcY, AcZ)) * RAD_TO_DEG;
    
    // Расчет приращения угла по гироскопу.
    gyroXrate = -((double)GyX / 131.0);
    
    // Обработка данных фильтром Калмана.
    kalAngleX = kalmanX.getAngle(accXangle, gyroXrate, (float)( micros() - timer)/1000000.0);
    timer = micros();
    
    // Компенсируем наклон
    if (kalAngleX > 2.0)
    {
      forward();
    }
    else if (kalAngleX < -2.0)
    {
      backward();
    }
    else {
      _stop();
    }
    delay(500); //
    Serial.print("kalAngleX="); 
    Serial.println(kalAngleX); //
  }
}
// Функции setup_motor_system(), forward(),backward() и _stop() взять из листинга 14.2

void _stop() {}
void forward() {}
void backward() {}
