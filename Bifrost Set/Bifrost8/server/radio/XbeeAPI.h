#ifndef _XBEEAPI_H_
#define _XBEEAPI_H_
#include "../ServerConstantes.h"

class XbeeAPI{
public:
    XbeeAPI() {};
    ~XbeeAPI() {};
    unsigned char stringSaida[TAMANHODOPACOTE];
    unsigned char* montarPacoteRS232(char stringEndereco[],  float velX,   float velY, float velAng, unsigned char CHUTE);
};
#endif
