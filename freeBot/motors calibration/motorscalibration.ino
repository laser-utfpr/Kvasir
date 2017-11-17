#include <Servo.h>

Servo servo1, servo2, servo3, servo4;
int motorNum;
int velAjuste;
void setup() {
  Serial.begin(57600);
  servo1.attach(4);
  servo2.attach(7);
  servo3.attach(10);
  servo4.attach(13);
}

void loop() {
  if(Serial.available() > 0)
  {
    servo1.write(110);
    servo2.write(107);
    servo3.write(95);
    //servo4.write(100);
    //Serial.println("digite o numero do motor");
    //motorNum = Serial.parseInt();
    //Serial.println("digite a velocidade");
    //while(1)
    //{
      //Serial.print("entrei");
    velAjuste = Serial.parseInt();
    //if(velAjuste==-1)
      //break;
    //if(motorNum==1) 113 107
    //{
     // servo1.write(velAjuste);
      //delay(100);
    //}
    //else if(motorNum==2)
    //{
     //  servo2.write(velAjuste);
     //  delay(100);
    //}
    //else if(motorNum==3)
    //{
     //  servo3.write(velAjuste);
      // delay(100);
    //}
    //else if(motorNum==4)
    //{
     //  servo4.write(velAjuste);113
      // delay(100);
    //}
    Serial.print(velAjuste);
    servo4.write(velAjuste);
    delay(100);
    //}
  }
}

