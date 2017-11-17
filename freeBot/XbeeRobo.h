#include "XbeeAPI.h"

#ifndef _XBEEROBO_H_
#define _XBEEROBO_H_

class XbeeRobo{
  private:
    //--Objetos
    XbeeAPI _xbee;
    //--variaveis
    char _enderecoCoordernador[16];//--Setar na construtura!!
    float _velocidadeX;
    float _velocidadeY;
    float _velAng;
    int _chute;
    int _statusRobo;
    int _status;
    int _habilitarTeste;
    int _pronto;
    
    char _velEnviar1;
    char _velEnviar2;
    char _velEnviar3;
    char _velEnviar4;
    char _cargaChute1;
    char _cargaChute2;
    char _chuteFunciona; 
    char *vetorTransmitir;
    float _converteVelocidade(char dadoIN1, char dadoIN2);
    
  public:
    //--Construtura
    XbeeRobo();
    ~XbeeRobo();
    
    void atualizarBuffer();
    int pronto();
    void enviarComando(char enderecoIN[]);
    float getVelX();
    float getVelY();
    float getVelAng();
    void receberRS232();
};
#endif


