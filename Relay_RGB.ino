#define RELAY_1 7

// библиотека для работы I²C
#include <Wire.h>
// библиотека для работы с модулями IMU
#include <TroykaIMU.h>

String val = "";
// создаём объект для работы с гироскопом
Gyroscope gyro;
// создаём объект для работы с акселерометром
Accelerometer accel;
// создаём объект для работы с компасом
Compass compass;
// создаём объект для работы с барометром
Barometer barometer;
 
// калибровочные значения компаса
// полученные в калибровочной матрице из примера «compassCalibrateMatrix»
const double compassCalibrationBias[3] = {
  524.21,
  3352.214,
  -1402.236
};
 
const double compassCalibrationMatrix[3][3] = {
  {1.757, 0.04, -0.028},
  {0.008, 1.767, -0.016},
  {-0.018, 0.077, 1.782}
};

void setup() 
{
  Serial.begin(115200);

   // инициализация гироскопа
  gyro.begin();
  // инициализация акселерометра
  accel.begin();
  // инициализация компаса
  compass.begin();
  // инициализация барометра
  barometer.begin();
  // калибровка компаса
  compass.calibrateMatrix(compassCalibrationMatrix, compassCalibrationBias);
  // выводим сообщение об удачной инициализации
  // Конфигурируем нужные пины на выход
  pinMode(7, OUTPUT);
  
  digitalWrite(RELAY_1, HIGH);
  delay(5000);

}

void loop() 
{

  // вывод угловой скорости в градусах в секунду относительно оси X
  Serial.print(gyro.readDegPerSecX());
  Serial.print(" ");
  // вывод угловой скорости в градусах в секунду относительно оси Y
  Serial.print(gyro.readDegPerSecY());
  Serial.print(" ");
  // вывод угловой скорости в градусах в секунду относительно оси Z
  Serial.print(gyro.readDegPerSecZ());
  Serial.print(" ");
  // вывод направления и величины ускорения в м/с² по оси X
  Serial.print(accel.readAX());
  Serial.print(" ");
  // вывод направления и величины ускорения в м/с² по оси Y
  Serial.print(accel.readAY());
  Serial.print(" ");
  // вывод направления и величины ускорения в м/с² по оси Z
  Serial.print(accel.readAZ());
  Serial.print(" ");
  // выводим азимут относительно оси Z
  Serial.print(compass.readAzimut());
  Serial.print(" ");
  // вывод значения абсолютного давления
  Serial.print(barometer.readPressureMillibars());
  Serial.print(" ");
  // вывод значения температуры окружающей среды
  Serial.print(barometer.readTemperatureC());
  Serial.print(" ");
  Serial.println();
  delay(500);
  
  
  if(Serial.available())
  {
    val = Serial.readString();
    
  }
        if(barometer.readTemperatureC() > val.toInt())
      {
        digitalWrite(RELAY_1, LOW);
      }
      else 
      {
        digitalWrite(RELAY_1, HIGH);
      }

}
