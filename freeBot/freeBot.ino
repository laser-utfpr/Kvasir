//Este programa tem por objetivo captar as informacoes recebidas de um transmissor e converte-las em conteudo util para o robo

#include "Principal.hpp"
#include <printf.h>

Principal principal = Principal();

void setup()
{
  //--Sets
     Serial.begin(BDRATE);
     pinMode(MOTOR1_PIN, OUTPUT);
     pinMode(MOTOR2_PIN, OUTPUT);
     pinMode(MOTOR3_PIN, OUTPUT);
     pinMode(MOTOR4_PIN, OUTPUT);
}

void loop()
{
    principal.start();
}
