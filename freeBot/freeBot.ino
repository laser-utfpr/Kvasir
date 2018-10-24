//Este programa tem por objetivo captar as informacoes recebidas de um transmissor e converte-las em conteudo util para o robo

#include "Principal.h"
#include <printf.h>

void setup() 
{
  //--Sets
     Serial.begin(BDRATE);
     pinMode(MOTOR1_PINO, OUTPUT);
     pinMode(MOTOR2_PINO, OUTPUT);
     pinMode(MOTOR3_PINO, OUTPUT);
     pinMode(MOTOR4_PINO, OUTPUT);
     PrincipalStart();
}

void loop() {}

