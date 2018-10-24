//biblioteca responsavel pelo vetor de dados que sera transmitido

#ifndef _SERIALPACKET_H_
#define _SERIALPACKET_H_
#include "../ServerConstantes.h"

class SerialPacket{
public:
    SerialPacket() {};
    ~SerialPacket() {};
    unsigned char stringSaida[TAMANHODOPACOTE];
    unsigned char* montarPacoteRS232(int nome, char stringEndereco[],  float velX,   float velY, float velAng, unsigned char CHUTE);
};
#endif
