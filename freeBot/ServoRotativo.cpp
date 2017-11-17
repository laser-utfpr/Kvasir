#include "ServoRotativo.h"


float ServoRotativo::getVelAjuste(){
  return _velAjuste;
  }

//void ServoRotativo::setCalibragem(){
  //Serial.print(Serial.available());
  //if(Serial.available() > 0)
//  {
  //_velAjuste = map(analogRead(_pinoADJ), 0, 1023, 0, 180);
  //  _velAjuste = Serial.read();
    //Serial.print("Teste ");
  //  _servo.write(_velAjuste,255,false);
//  switch(_motorNum)
//  {
//    case 1:
//    EEPROM.write(constante.MOTOR1_ENDERECO,_velAjuste); break; 
//    case 2:
//    EEPROM.write(constante.MOTOR2_ENDERECO,_velAjuste); break;
//    case 3:
//    EEPROM.write(constante.MOTOR3_ENDERECO,_velAjuste); break;
//    case 4:
//    EEPROM.write(constante.MOTOR4_ENDERECO,_velAjuste); break;
 // }
  //delay(100);
  //}
  
  //Serial.print( _motorNum);
//}

void ServoRotativo::setServoMotor(int pinoPWMIN, float velocidadeMaximaIN, int motorNum){
  _pinoPWM = pinoPWMIN;
  //_pinoADJ = pinoADJIN;
  _servo.attach(_pinoPWM);//--Fazer uma construtora decente!!
  _motorNum = motorNum;
  switch(_motorNum)
  {
    case 1:
    _velAjuste = constante.MOTOR1_VEL_AJUSTE; break;
    case 2:
    _velAjuste = constante.MOTOR2_VEL_AJUSTE; break;
    case 3:
    _velAjuste = constante.MOTOR3_VEL_AJUSTE; break;
    case 4:
    _velAjuste = constante.MOTOR4_VEL_AJUSTE; break;
  }
//  _velAjuste = map(analogRead(_pinoADJ), 0, 1023, 0, 180);
  _velocidadeMaxima = velocidadeMaximaIN;
//  setCalibragem();
  _servo.write(_velAjuste,255,false);//--Manda iniciar com o motor parado
  }

void ServoRotativo::setVelocidade(float velocidadeIN){
    /*
    int pwm;
    //--pwm = (int)(vel *180/.6)+90;//--FULL RANGE(0->255)(PWM)
    pwm = (int)((velocidadeIN+.3)*50/.6)+65; //--Zona linear (65->115)(PWM)
    _servo.write(pwm ,255,false);
    //_servo.write(90 + angulo + _velAjuste,255,false);
    */   
  float angulo;
   //angulo = map(abs(velocidadeIN), 0, _velocidadeMaxima, 0, 180); //--Arruma a escala da velocidade, para a que provoca o mobimento nos servos!!
   //angulo = abs((velocidadeIN*90)/_velocidadeMaxima);
   angulo = (velocidadeIN*90)/_velocidadeMaxima; 
   Serial.print(_motorNum);
   Serial.print("  ");
 Serial.println(angulo); 
   if(velocidadeIN==0)
    _servo.detach();
   else{ 
    _servo.attach(_pinoPWM);
    //if(velocidadeIN>0)
      _servo.write(angulo + _velAjuste,255,false);//--sentido horário se angulo é positivo ou ~

    //else if(velocidadeIN<0)
     // _servo.write( _velAjuste - angulo,255,false);//--sentido anti horario
   }
      
   //Serial.println(90 - angulo + _velAjuste); 
   
}
  
