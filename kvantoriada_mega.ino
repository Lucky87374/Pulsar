  // библиотека для работы с датчиками MQ (Troyka-модуль)
#include <TroykaMQ.h>
// библиотека для работы с датчиками серии DHT
#include <TroykaDHT.h>
 
// имя для пина, к которому подключен датчик
#define PIN_MQ2         A0
// имя для пина, к которому подключен нагреватель датчика
#define PIN_MQ2_HEATER  2

// имя для пина, к которому подключен датчик
#define PIN_MQ5         A1
// имя для пина, к которому подключен нагреватель датчика
#define PIN_MQ5_HEATER  3

/*// имя для пина, к которому подключен датчик
#define PIN_MQ7         A2
// имя для пина, к которому подключен нагреватель датчика
#define PIN_MQ7_HEATER  4
*/
// имя для пина, к которому подключен датчик
#define PIN_MQ8         A3
// имя для пина, к которому подключен нагреватель датчика
#define PIN_MQ8_HEATER  5

// имя для пина, к которому подключен датчик
#define PIN_MQ135         A4
// имя для пина, к которому подключен нагреватель датчика
#define PIN_MQ135_HEATER  6
 
// создаём объект для работы с датчиком
// и передаём ему номер пина выходного сигнала и нагревателя
MQ2 mq2(PIN_MQ2, PIN_MQ2_HEATER);
MQ5 mq5(PIN_MQ5, PIN_MQ5_HEATER);
//MQ7 mq7(PIN_MQ7, PIN_MQ7_HEATER);
MQ8 mq8(PIN_MQ8, PIN_MQ8_HEATER);
MQ135 mq135(PIN_MQ135);

DHT dht(7, DHT21);

String val = "";

float mq2Ratio=0;
float mq2LPG=0;
float mq2Methane=0;
float mq2Smoke=0;
float mq2Hydrogen=0;
float mq5Ratio=0;
float mq5LPG=0;
float mq5Methane=0;
float mq8Ratio=0;
float mq8Hydrogen=0;
//float mq7Ratio=0;
//float mq7CarbonMonoxide=0;
float mq135Ratio=0;
float mq135CO2=0;
void setup()
{
  // открываем последовательный порт
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  // включаем нагреватель
  mq2.heaterPwrHigh();
  mq5.heaterPwrHigh();
  //mq7.cycleHeat();
  mq8.heaterPwrHigh();
  mq135.heaterPwrHigh();
  dht.begin();
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
}




void loop(){
  // если прошёл интервал нагрева датчика
  // и калибровка не была совершена
  if (!mq2.isCalibrated() && mq2.heatingCompleted()) {
    // выполняем калибровку датчика на чистом воздухе
    mq2.calibrate();
  }
  // если прошёл интервал нагрева датчика
  // и калибровка была совершена
  if (mq2.isCalibrated() && mq2.heatingCompleted()) {
    // выводим отношения текущего сопротивление датчика
    // к сопротивлению датчика в чистом воздухе (Rs/Ro)
    mq2Ratio=mq2.readRatio();
    mq2LPG=mq2.readLPG();
    mq2Methane=mq2.readMethane();
    mq2Smoke=mq2.readSmoke();
    mq2Hydrogen=mq2.readHydrogen();
    Serial.print(mq2Ratio);
    Serial.print(" ");
    Serial.print(mq2LPG);
    Serial.print(" ");
    Serial.print(mq2Methane);
    Serial.print(" ");
    Serial.print(mq2Smoke);
    Serial.print(" ");
    Serial.print(mq2Hydrogen);
    Serial.print(" ");

    Serial1.print("mq2Ratio = ");
    Serial1.println(mq2Ratio);
    Serial1.print("mq2LPG = ");
    Serial1.println(mq2LPG);
    Serial1.print("mq2Methane = ");
    Serial1.println(mq2Methane);
    Serial1.print("mq2Smoke = ");
    Serial1.println(mq2Smoke);
    Serial1.print("mq2Hydrogen = ");
    Serial1.println(mq2Hydrogen);
    delay(100);
    Serial2.print("mq2Ratio = ");
    Serial2.println(mq2Ratio);
    Serial2.print("mq2LPG = ");
    Serial2.println(mq2LPG);
    Serial2.print("mq2Methane = ");
    Serial2.println(mq2Methane);
    Serial2.print("mq2Smoke = ");
    Serial2.println(mq2Smoke);
    Serial2.print("mq2Hydrogen = ");
    Serial2.println(mq2Hydrogen);
  }





  // если прошёл интервал нагрева датчика
  // и калибровка не была совершена
  if (!mq5.isCalibrated() && mq5.heatingCompleted()) {
    // выполняем калибровку датчика на чистом воздухе
    mq5.calibrate();
  }
  // если прошёл интервал нагрева датчика
  // и калибровка не была совершена
  /*if (!mq7.isCalibrated() && mq7.atHeatCycleEnd()) {
    // выполняем калибровку датчика на чистом воздухе
    mq7.calibrate();
    // запускаем термоцикл
    mq7.cycleHeat();
  }
  */
  if (!mq8.isCalibrated() && mq8.heatingCompleted()) {
    // выполняем калибровку датчика на чистом воздухе
    mq8.calibrate();
  }
  // если прошёл интервал нагрева датчика
  // и калибровка была совершена
  if (mq5.isCalibrated() && mq5.heatingCompleted()) {
    // выводим отношения текущего сопротивление датчика
    // к сопротивлению датчика в чистом воздухе (Rs/Ro)
    mq5Ratio=mq5.readRatio();
    mq5LPG=mq5.readLPG();
    mq5Methane=mq5.readMethane();
    

    Serial.print(mq5Ratio);
    Serial.print(" ");
    Serial.print(mq5LPG);
    Serial.print(" ");
    Serial.print(mq5Methane);
    Serial.print(" ");

    Serial1.print("mq5Ratio = ");
    Serial1.println(mq5Ratio);
    Serial1.print("mq5LPG = ");
    Serial1.println(mq5LPG);
    Serial1.print("mq5Methane = ");
    Serial1.println(mq5Methane);
    delay(100);
    Serial2.print("mq5Ratio = ");
    Serial2.println(mq5Ratio);
    Serial2.print("mq5LPG = ");
    Serial2.println(mq5LPG);
    Serial2.print("mq5Methane = ");
    Serial2.println(mq5Methane);
    // запускаем термоцикл
    
  }



  // если прошёл интервал нагрева датчика
  // и калибровка была совершена
  if (mq8.isCalibrated() && mq8.heatingCompleted()) {
    mq8Ratio=mq8.readRatio();
    mq8Hydrogen=mq8.readHydrogen();
    Serial.print(mq8Ratio);
    Serial.print(" ");
    Serial.print(mq8Hydrogen);
    Serial.print(" ");

    Serial1.print("mq8Ratio = ");
    Serial1.println(mq8Ratio);
    Serial1.print("mq8Hydrogen = ");
    Serial1.println(mq8Hydrogen);
    delay(100);
    Serial2.print("mq8Ratio = ");
    Serial2.println(mq8Ratio);
    Serial2.print("mq8Hydrogen = ");
    Serial2.println(mq8Hydrogen);
  }



 /* if (mq7.isCalibrated() && mq7.atHeatCycleEnd()) {
    if(mq7.readRatio() != mq7Ratio && mq7.readCarbonMonoxide() != mq7CarbonMonoxide)
    {
    mq7Ratio=mq7.readRatio();
    mq7CarbonMonoxide=mq7.readCarbonMonoxide();
    }
    Serial.print(mq7Ratio);
    Serial.print(" ");
    Serial.print(mq7CarbonMonoxide);
    Serial.print(" ");
    delay(100);
    // запускаем термоцикл
    mq7.cycleHeat();
  }
*/
  


  // если прошёл интервал нагрева датчика
  // и калибровка не была совершена
  if (!mq135.isCalibrated() && mq135.heatingCompleted()) {
    // выполняем калибровку датчика на чистом воздухе
    mq135.calibrate();
  }
  // если прошёл интевал нагрева датчика
  // и калибровка была совершена
  if (mq135.isCalibrated() && mq135.heatingCompleted()) {
    mq135Ratio=mq135.readRatio();
    mq135CO2=mq135.readCO2();
    Serial.print(mq135Ratio);
    Serial.print(" ");
    Serial.print(mq135CO2);
    Serial.print(" ");

    Serial1.print("mq135Ratio = ");
    Serial1.println(mq135Ratio);
    Serial1.print("mq135CO2 = ");
    Serial1.println(mq135CO2);
    delay(100);
    Serial2.print("mq135Ratio = ");
    Serial2.println(mq135Ratio);
    Serial2.print("mq135CO2 = ");
    Serial2.println(mq135CO2);
    

  }

// считывание данных с датчика
  dht.read();
  // проверяем состояние данных
  switch(dht.getState()) {
    // всё OK
    case DHT_OK:
      // выводим показания влажности и температуры
      Serial.print(dht.getTemperatureK());
      Serial.print(" ");
      Serial.print(dht.getTemperatureF());
      Serial.print(" ");
      Serial.print(dht.getTemperatureC());
      Serial.print(" ");
      Serial.println(dht.getHumidity());

      Serial1.print("TemperatureK = ");
      Serial1.println(dht.getTemperatureK());
      Serial1.print("TemperatureF = ");
      Serial1.println(dht.getTemperatureF());
      Serial1.print("TemperatureC = ");
      Serial1.println(dht.getTemperatureC());
      Serial1.print("Humidity = ");
      Serial1.println(dht.getHumidity());
      Serial1.println(" ");
      delay(100);
      Serial2.print("TemperatureK = ");
      Serial2.println(dht.getTemperatureK());
      Serial2.print("TemperatureF = ");
      Serial2.println(dht.getTemperatureF());
      Serial2.print("TemperatureC = ");
      Serial2.println(dht.getTemperatureC());
      Serial2.print("Humidity = ");
      Serial2.println(dht.getHumidity());
      Serial2.println(" ");

      break;
    // ошибка контрольной суммы
    case DHT_ERROR_CHECKSUM:
      Serial.println("Checksum error");
      break;
    // превышение времени ожидания
    case DHT_ERROR_TIMEOUT:
      Serial.println("Time out error");
      break;
    // данных нет, датчик не реагирует или отсутствует
    case DHT_ERROR_NO_REPLY:
      Serial.println("Sensor not connected");
      break;
  }
delay(1000);
}


