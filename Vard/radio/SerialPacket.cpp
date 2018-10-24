#include "SerialPacket.h"

unsigned char* SerialPacket::montarPacoteRS232(int nome, char stringEndereco[],  float velX,   float velY, float velAng, unsigned char CHUTE)
{
    int i;
    char string_velX[4];
    char string_velY[4];
    char string_velAng[4];

    *((float*)&string_velX) = velX;
    *((float*)&string_velY) = velY;
    *((float*)&string_velAng) = velAng;

    // string saida foi craida com base na documentacao da biblioteca para nrf24l01 -- http://tmrh20.github.io/RF24/ //nrf24l01
    stringSaida[0] = BEGIN;  //--Padr�o
    stringSaida[1] = stringEndereco[0];  //--Adress
    stringSaida[2] = stringEndereco[1];  //--Adress
    stringSaida[3] = stringEndereco[2];  //--Adress
    stringSaida[4] = stringEndereco[3];  //--Adress
    stringSaida[5] = stringEndereco[4]; //--Adress
    stringSaida[6] = nome; //--key
    stringSaida[7] = KEY;
    for(i=0; i<4; i++)
    {
        stringSaida[8+i]=string_velX[i];
        stringSaida[12+i]=string_velY[i];
        stringSaida[16+i]=string_velAng[i];
    }
    return stringSaida;
}
