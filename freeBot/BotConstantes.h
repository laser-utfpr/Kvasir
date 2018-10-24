#ifndef _CONSTANTES_H_
#define _CONSTANTES_H_

#define ATIVAR_TESTE 0 //se 1, ativa o modo teste, onde o robo vai nas direcoes determinadas em software.cpp

#define BDRATE 115200 //frequencia padrao do Arduino FIO que permite que o mesmo seja programado pelo Xbee
//pinagem nrf24l01 para arduino nano
//GND -- GND
//VCC -- 3.3V
//CE -- CE_PIN
//CSN -- CSN_PIN
//SCK -- digIO 13
//MOSI -- digIO 11
//MISO -- digIO 12
//IRQ -- NONE

//sets para funcionamento do nRF24L01. Documentacao em http://tmrh20.github.io/RF24/classRF24.html#a5e6e5a5f6c85d2638381cab2c0f3702e
#define CE_PIN 7
#define CSN_PIN 8
#define DELAY_TRANS 0 //delay de transmissao
#define RETRIES 3 //numero de tentativas de envio para os receptores
#define CHANNEL 33 //canal RF de comunicacao, 0-125 (2400+CHANNEL MHZ)
#define W_ADDRESS 5 //quantidade de bytes do endereco
#define W_DATA 14 //quantidade de bytes do pacote para envio
#define DATA_RATE RF24_2MBPS //velocidade de transmissao de dados
#define ADDRESS "ALLAN"
#define NAME 4

#define DADOS 12 //tamanho de dados efetivamente usados no programa arduino (no momento, 3 velocidades float)
#define KEY 0xa0 //chave que indica o inicio de um pacote efetivo de velocidades

#define ANG 0 //angulo entre o plano de  movimentacao e o plano do robo
#define VELOCIDADE_MAXIMA 0.3 //velocidade maxima do robo
#define RAIO_RODA 0.0375 //raio da roda

//pinagem motores, dependera da placa de alimentacao criada.
//ATENCAO: atentar para a correta localizacao, pois a pinagem errada podera queimar o Arduino, ja que uma saida estara recebendo a tensao do motor ou terra
#define MOTOR1_PINO 3
#define MOTOR2_PINO 4
#define MOTOR3_PINO 5
#define MOTOR4_PINO 6

//velocidade de parada. Ajustes digitais podem ser feitos no programa motorscalibration.ino, na pasta MotorsCalibration
#define MOTOR1_VEL_AJUSTE 109
#define MOTOR2_VEL_AJUSTE 92
#define MOTOR3_VEL_AJUSTE 96
#define MOTOR4_VEL_AJUSTE 101

#endif
