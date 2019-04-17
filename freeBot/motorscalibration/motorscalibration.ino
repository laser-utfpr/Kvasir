#include <Servo.h>

Servo servo1, servo2, servo3, servo4;
int motorNum;
int velAjuste;
void setup() {
  Serial.begin(57600);
  servo1.attach(3);
  servo2.attach(4);
  servo3.attach(5);
  servo4.attach(6);
}

void loop() 
{
    Serial.println("digite o numero do motor");
    servo1.write(84);
    servo2.write(90);
    servo3.write(85);
    servo4.write(77);
    /*if(Serial.available() > 0)
    {
        motorNum = Serial.parseInt();
        Serial.println("digite a velocidade");
        while(1)
        {
            if(Serial.available() > 0)
            {
                velAjuste = Serial.parseInt();
                if(velAjuste==-1)
                {
                    break;
                }    
                if(motorNum==1)
                {
                  servo1.write(velAjuste);
                  delay(100);
                }
                else if(motorNum==2)
                {
                  servo2.write(velAjuste);
                  delay(100);
                }
                else if(motorNum==3)
                {
                  servo3.write(velAjuste);
                  delay(100);
                }
                else if(motorNum==4)
                {
                  servo4.write(velAjuste);
                  delay(100);
                }
            }
            Serial.print("Velocidade igual ");
            Serial.println(velAjuste);
      //servo4.write(velAjuste);
      //delay(100);
        }
    }*/
}
