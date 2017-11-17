#include "Movimentacao.h"
#include <Arduino.h>

//--Construtoras  
Movimentacao::Movimentacao(){
    
    _motor1.setServoMotor(_pinagem.MOTOR1_PINO, _constantes.VELOCIDADE_MAXIMA, 1);
    _motor2.setServoMotor(_pinagem.MOTOR2_PINO, _constantes.VELOCIDADE_MAXIMA, 2);
    _motor3.setServoMotor(_pinagem.MOTOR3_PINO, _constantes.VELOCIDADE_MAXIMA, 3);
    _motor4.setServoMotor(_pinagem.MOTOR4_PINO, _constantes.VELOCIDADE_MAXIMA, 4);

    _velocidade.motor1 = 0;
    _velocidade.motor2 = 0;
    _velocidade.motor3 = 0;
    _velocidade.motor4 = 0;
  
  }

//--Métodos

void Movimentacao::mover(float velXIN, float velYIN, float w){
//if(operacaoIN==0){
     _calculo(velXIN,velYIN, w); 

//    Serial.print("Velocidade do Motor 1:");
 //   Serial.println(_velocidade.motor1);
//    Serial.print(" Potencia de PWM: ");
     _motor1.setVelocidade(_velocidade.motor1);
//    Serial.print("Velocidade do Motor 2:");   
 //   Serial.println(_velocidade.motor2);
//    Serial.print(" Potencia de PWM: ");
     _motor2.setVelocidade(_velocidade.motor2);
//    Serial.print("Velocidade do Motor 3:");   
 //   Serial.println(_velocidade.motor3);
//    Serial.print(" Potencia de PWM: ");
     _motor3.setVelocidade(_velocidade.motor3);
//    Serial.print("Velocidade do Motor 4:");
 //   Serial.println(_velocidade.motor4);
//    Serial.print(" Potencia de PWM: ");   
     _motor4.setVelocidade(_velocidade.motor4);
//    Serial.println(""); 
}
 //else{
   //   _motor1.setCalibragem();
   //   _motor2.setCalibragem();
   //   _motor3.setCalibragem();
   //   _motor4.setCalibragem();

      //--Auxilia a regulagem:
   //   Serial.print("Ajuste do Motor 1:");
   //   Serial.println(_motor1.getVelAjuste());
   //   Serial.print("Ajuste do Motor 2:");
   //   Serial.println(_motor2.getVelAjuste());
   //   Serial.print("Ajuste do Motor 3:");
   //   Serial.println(_motor3.getVelAjuste());
   //   Serial.print("Ajuste do Motor 4:");
   //   Serial.println(_motor4.getVelAjuste());
   //   Serial.println("");
  //}
//}
void Movimentacao::_calculo(float velXIN, float velYIN, float w){
  //--float vetorANG = atan(velYIN/velXIN)/4;//--calcula o angulo e converte pra radiano
  float  vox=0, voy=0;
 // modulo = sqrt((velXIN*velXIN) + (velYIN*velYIN));
//  angulo = (atan(y/x)*180)/3.14;
  //--Robô Visto de Cima
  //            _
  //      M1    /|
  //   ___|___ /
  //   |     |
  //M4-|CIMA!|-M2
  //   |     |
  //    -----
  //      |
  //      M3

  //--Nova tentativa de Omni!:
  //nao funciona
/* if(velXIN == 0 && velYIN == 0){
    _velocidade.motor1 = 0;
    _velocidade.motor2 = 0;
    _velocidade.motor3 = 0;
    _velocidade.motor4 = 0;
  }
 else if(abs(velXIN)>=abs(velYIN) && velXIN != 0 && velYIN !=0){
    anguloX = atan(velYIN/velXIN)*180/PI;
    _velocidade.motor1 =      (1-(anguloX/45))*modulo*velXIN/abs(velXIN);
    _velocidade.motor2 = (-1)*(1+(anguloX/45))*modulo*velXIN/abs(velXIN);
    _velocidade.motor3 = (-1)*(1-(anguloX/45))*modulo*velXIN/abs(velXIN);
    _velocidade.motor4 =      (1+(anguloX/45))*modulo*velXIN/abs(velXIN);
 }
 else if(abs(velYIN)>abs(velXIN)){ 
    anguloY = atan(velXIN/velYIN)*180/PI;
    _velocidade.motor1 = (-1)*(1+(anguloY/45))*modulo*velYIN/abs(velYIN);
    _velocidade.motor2 =      (1-(anguloY/45))*modulo*velYIN/abs(velYIN);
    _velocidade.motor3 =      (1+(anguloY/45))*modulo*velYIN/abs(velYIN);
    _velocidade.motor4 = (-1)*(1-(anguloY/45))*modulo*velYIN/abs(velYIN);
  }
  else{
    _velocidade.motor1 = 0;
    _velocidade.motor2 = 0;
    _velocidade.motor3 = 0;
    _velocidade.motor4 = 0;
    }*/
    //ang é a relação entre a referência do robo e a referencia da camera. Usando SI. Por enquanto ang é zero
    vox=cos(_constantes.ANG)*velXIN+sin(_constantes.ANG)*velYIN;
    voy=-sin(_constantes.ANG)*velXIN+cos(_constantes.ANG)*velYIN;
    _velocidade.motor1 = vox+w*_constantes.RAIO_ROBO;
    _velocidade.motor2 = -voy+w*_constantes.RAIO_ROBO;
    _velocidade.motor3 = -vox+w*_constantes.RAIO_ROBO;
    _velocidade.motor4 = voy+w*_constantes.RAIO_ROBO;
    
    
    
  //--Teste Direto
  //_velocidade.motor1 = -velXIN;//--Motor da Frente
  //_velocidade.motor2 = -velYIN;//--Motor da esquerda
  //_velocidade.motor3 = velXIN;//--Motor de trás
  //_velocidade.motor4 = velYIN;//--Motor da direita

 }
