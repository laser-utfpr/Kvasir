#ifndef _BOTCONSTANTS_H_
#define _BOTCONSTANTS_H_

//#define XBEE //descomentar se estiver usando xbee

#ifndef XBEE
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
    #define W_DATA 14 //quantidade de bytes do pacote para envio - 3 velocidades 1 nome e 1 inicio
    #define DATA_RATE RF24_2MBPS //velocidade de transmissao de dados
    #define ADDRESS "ALEFE"
    #define NAME 0
    //pinagem motores, dependera da placa de alimentacao criada.
    //ATENCAO: atentar para a correta localizacao, pois a pinagem errada podera queimar o Arduino, ja que uma saida estara recebendo a tensao do motor ou terra
    #define MOTOR1_PIN 3
    #define MOTOR2_PIN 4
    #define MOTOR3_PIN 5
    #define MOTOR4_PIN 6

#else
    #define BDRATE 57600 //frequencia padrao do Arduino FIO que permite que o mesmo seja programado pelo Xbee
    #define W_DATA 28 //24 efetivo, 3 padrao, 1 checksu
    //pinagem motores, dependera da placa de alimentacao criada.
    //ATENCAO: atentar para a correta localizacao, pois a pinagem errada podera queimar o Arduino, ja que uma saida estara recebendo a tensao do motor ou terra
    #define MOTOR1_PIN 4
    #define MOTOR2_PIN 7
    #define MOTOR3_PIN 10
    #define MOTOR4_PIN 13
#endif

#define DATA_SIZE 12 //tamanho de dados efetivamente usados no programa arduino (no momento, 3 velocidades float)
#define KEY 0xa0 //chave que indica o inicio de um pacote efetivo de velocidades
#define COMMUNICATION_DELAY 10 //delay da communicacao em milissegundos

#define ANG 0 //angulo entre o plano de  movimentacao e o plano do robo
#define MAX_SPEED 0.3 //velocidade maxima do robo
#define WHEEL_RADIUS 0.0375 //raio da roda

//velocidade de parada. Ajustes digitais podem ser feitos no programa motorscalibration.ino, na pasta MotorsCalibration
#define MOTOR1_ADJUST_SPEED 80
#define MOTOR2_ADJUST_SPEED 85
#define MOTOR3_ADJUST_SPEED 80
#define MOTOR4_ADJUST_SPEED 85

#endif
