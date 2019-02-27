//biblioteca feita para guardar as constantes de Vard

#ifndef _VARDCONSTANTS_H_
#define _VARDCONSTANTS_H_
#ifndef XBEE
    #define BDRATE 115200 //frequencia de comunicacao do radio
    #define PACKET_SIZE 20
#else
    #define BDRATE 57600 //frequencia padrao do Arduino FIO que permite que o mesmo seja programado pelo Xbee
    #define PACKET_SIZE 28 //24 efetivo, 3 padrao, 1 checksu
    #define SHIPPING_SIZE 0x18 //tamanho efetivo em hexa. Maximo 108 bytes (8 adress, 100 data)
    //macros definidas com base em https://www.digi.com/resources/documentation/digidocs/PDFs/90000982.pdf
    #define ACK 0x00 //opcao para ACK.
    #define OP_MODE 0x00 //Modo de operacao do XBEE
    #define UART 0x01 //Sem padronizacao na internet. A principio se 0, nao havera resposta por parte do receptor
#endif
#define CPORT_NR 16
#define KEY 0xa0
#define BEGIN 0x77
#define COMMUNICATION_DELAY 3350//delay em us da comunicacao 3350, eh o maximo que o arduino le sem baguncar pacotes


#endif
