#include "XbeeAPI.h"

unsigned char* XbeeAPI::montarPacoteRS232(char stringEndereco[],  float velX,   float velY, float velAng, unsigned char CHUTE)
{
    int i, j, endereco[8], aux1;
    char string_velX[4];
    char string_velY[4];
    char string_velAng[4];

    *((float*)&string_velX) = velX;
    *((float*)&string_velY) = velY;
    *((float*)&string_velAng) = velAng;

    j=0;
    for(i=0; i<16; i++)
    {
        //--para numeros: em ascii de 48 até 57
        if(stringEndereco[i]>=48 && stringEndereco[i]<=57)
        {
            aux1 = stringEndereco[i]-48;
        }
        //--para letras: em ascii de
        if(stringEndereco[i]>=97 && stringEndereco[i]<=102)
        {
            aux1 = stringEndereco[i]-97+10;
        }
        //--para numeros pares, ele "empurra e grava"
        //--para numeros impares ele faz "ou" e grava
        if(i%2==0)
        {
            endereco[j]=aux1<<4;
        }
        else
        {
            endereco[j]=endereco[j] | aux1;
            j++;
        }
    }
    //--Fim do conversor
    //--7E 00 7D[2] 31 10 01 00 7D 33 A2 00 40 DA DC 05 FF FE 00 00 50 C0 00 31
    stringSaida[0] = 0x7E;  //--Padrão
    stringSaida[1] = 0x00;  //--MSB length packet
    stringSaida[2] = TAMANHOENVIO; //--LSB lenght packet
    stringSaida[3] = 0x00;  //--Frame type - Operation mode
    stringSaida[4] = 0x01;  //--UART to correlate with a subsequent ACK. If 0, no send response (Without pattern in the internet)
    stringSaida[5] = endereco[0];  //--MSB of adress
    stringSaida[6] = endereco[1];  //--Adress
    stringSaida[7] = endereco[2];  //--Adress
    stringSaida[8] = endereco[3];  //--Adress
    stringSaida[9] = endereco[4];  //--Adress
    stringSaida[10] = endereco[5]; //--Adress
    stringSaida[11] = endereco[6]; //--Adress
    stringSaida[12] = endereco[7]; //--LSB of adress
    stringSaida[13] = 0x10; //--byte of options to ACK
    stringSaida[14] = 0xa0; //--key
    for(i=0; i<4; i++)
    {
        stringSaida[15+i]=string_velX[i];
        stringSaida[19+i]=string_velY[i];
        stringSaida[23+i]=string_velAng[i];
    }

    //--Calcular CheckSum
    aux1=0;
    for(i=3; i<(TAMANHODOPACOTE-1); i++)
    {
        aux1=aux1+stringSaida[i];
    }
    aux1=0xff-(aux1&0xff);
    stringSaida[TAMANHODOPACOTE-1] = aux1; //--Checksum
    return stringSaida;
}

