#include "Principal.h"
#include "Constantes.h"

void setup() {
  //--Sets
    Serial.begin(57600);
    Pinagem pino;
    Constantes constante;
     pinMode(pino.MOTOR1_PINO, OUTPUT);
     pinMode(pino.MOTOR2_PINO, OUTPUT);
     pinMode(pino.MOTOR3_PINO, OUTPUT);
     pinMode(pino.MOTOR4_PINO, OUTPUT);
     
     //--Debug
     pinMode(14, OUTPUT);
     
    Principal START;
}

void loop() {
  
}
//Agora ele gira!
//--Freebot v1.019
//--Implementar cabeçalhos do autor
//--NOTAS DA VERSÂO
  //--Valores de pinis ajustados para nova placa.
  //--O MODO CALIBRAGEM envia comandos para a serial para que seja possível acompanhar numericamente o ajuste.
  //--PS: A calibragem DEVE SER realizada com o XBee desligado!!

    
//--FALTA IMPLEMENTAR:
    //--Cálculos Corretos da recepção de dados

    //--Ajustar comunicaço, acredido que ela esteja programada pra a velocidade mxima do jr, alem de, nao possuir "GIRAR SOBRE PROPRIO EIXO" 
      //--A principio os cálculos da comunicação foram refeitos usando o VSSL
//--BUGS NAO RESOLVIDOS:
    //--Atençao, a funçao maps() pode dar bosta, evitar usar!! (REMOVER TUDO!!)

//--SOFTWARE PRONTO PARA TESTE!!
    //--Testar Comunicaço RE-Testar Omnidirecional
    //--Ver se funciona o conjunto todo
    //o negocio n funciona ver o calculo

