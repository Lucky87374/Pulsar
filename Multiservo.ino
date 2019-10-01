#include <Wire.h>
#include <Multiservo.h>

Multiservo servo1;
Multiservo servo2;
Multiservo servo3;
Multiservo servo4;
Multiservo servo5;
Multiservo servo6;
Multiservo servo7;
Multiservo servo8;

int val = 0;

//ServoSmooth servos[AMOUNT];

void setup() {
   servo1.attach(17);
   servo2.attach(16);
   servo3.attach(15);
   servo4.attach(14);
   servo5.attach(13);
   servo6.attach(3);
   servo7.attach(0);
   servo8.attach(1);
   Serial.begin(9600);

}

void loop() {
  
    if(Serial.available())
    {
      val = Serial.readString().toInt();
      Serial.println(val);
      if(val == 0)
      {
        servo_close();
      }
      else if(val == 1)
      {
        servo_open();
      }
      else if (val == 2)
      {
        servo7.write(90); 
      }
      else if (val == 3)
      {
        servo7.write(120);
      }
      else if (val == 4)
      {
        servo8.write(100);
      }
      else if (val == 5)
      {
        servo8.write(20);
      }
    }
    
}

void servo_open(){
    for(int i=0;i<180;i++)
    {
      servo1.write(i);
      delay(10);
      servo2.write(i);
      delay(10);
      servo3.write(i);
      delay(10);
      servo4.write(i);
      delay(10);
      servo5.write(i);
      delay(10);
      servo6.write(i);
      delay(10);
    }
}

void servo_close(){
    for(int i=180;i>0;i--)
    {
      servo1.write(i);
      delay(10);
      servo2.write(i);
      delay(10);
      servo3.write(i);
      delay(10);
      servo4.write(i);
      delay(10);
      servo5.write(i);
      delay(10);
      servo6.write(i);
      delay(10);
    }
}

