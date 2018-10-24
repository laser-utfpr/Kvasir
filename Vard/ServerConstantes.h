#ifndef _SERVERCONSTANTES_H_
#define _SERVERCONSTANTES_H_

#define BDRATE 115200 //frequencia padrao do Arduino FIO que permite que o mesmo seja programado pelo Xbee
#define CPORT_NR 16

#define TAMANHODOPACOTE 20 //24 efetivo, 3 padrao, 1 checksu
//#define TAMANHODOPACOTERX 31
//#define TAMANHORECEBIDO 0x1f
#define KEY 0xa0
#define BEGIN 0x77

//macros definidas com base em https://www.digi.com/resources/documentation/digidocs/PDFs/90000982.pdf
#define ACK 0x00 //opcao para ACK.
#define OP_MODE 0x00 //Modo de operacao do XBEE
#define UART 0x01 //Sem padronizacao na internet. A principio se 0, nao havera resposta por parte do receptor

#define LINHAS_ROBOS 300
#define COLUNAS_MAC 30
#define COLUNAS_NUMBERS 30
#define LINHAS 10
#define COLUNAS 500
#define TAMANHO_DO_LOG 1000

#endif
