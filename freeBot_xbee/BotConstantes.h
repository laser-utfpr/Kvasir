#ifndef _CONSTANTES_H_
#define _CONSTANTES_H_

#define ATIVAR_TESTE 0 //se 1, ativa o modo teste, onde o robo vai nas direcoes determinadas em software.cpp

#define BDRATE 57600 //frequencia padrao do Arduino FIO que permite que o mesmo seja programado pelo Xbee

#define TAMANHODOPACOTE 31 //24 efetivo, 3 padrao, 1 checksu
#define TAMANHORECEBIDO 0x1B //tamanho efetivo em hexadecimal
#define DADOS 12 //tamanho de dados efetivamente usados no programa arduino (no momento, 3 velocidades float)
#define KEY 0xa0 //chave que indica o inicio de um pacote efetivo de velocidades

#define ANG 0 //angulo entre o plano de  movimentacao e o plano do robo
#define VELOCIDADE_MAXIMA 0.3 //velocidade maxima do robo
#define RAIO_RODA 0.0375 //raio da roda

//pinagem motores, dependera da placa de alimentacao criada. 
//ATENCAO: atentar para a correta localizacao, pois a pinagem errada podera queimar o Arduino, ja que uma saida estara recebendo a tensao do motor ou terra
#define MOTOR1_PINO 4
#define MOTOR2_PINO 7
#define MOTOR3_PINO 10
#define MOTOR4_PINO 13

//velocidade de parada. Ajustes digitais podem ser feitos no programa motorscalibration.ino, na pasta Motors Calibration
#define MOTOR1_VEL_AJUSTE 109
#define MOTOR2_VEL_AJUSTE 106
#define MOTOR3_VEL_AJUSTE 95
#define MOTOR4_VEL_AJUSTE 93

#endif
