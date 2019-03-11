#include "SerialCommunication.hpp"
#include <iomanip>

SerialCommunication::SerialCommunication()
{
    if(RS232_OpenComport(CPORT_NR, BDRATE, "8N1"))
    {
        printf("AVISO: NENHUMA serial encontrada!!\n");
        exit(1);
    }
    else
    {
        RS232_enableDTR(CPORT_NR);
        RS232_enableRTS(CPORT_NR);
    }
}

SerialCommunication::~SerialCommunication()
{
    RS232_CloseComport(CPORT_NR);
}

void SerialCommunication::sendData()
{
    RS232_SendBuf(CPORT_NR, (unsigned char*) data, PACKET_SIZE);
}

void SerialCommunication::mountPacket(int name, char *rf_address, float vel_x, float vel_y, float vel_ang)
{
    int i;
    char string_velX[4];
    char string_velY[4];
    char string_velAng[4];

    *((float*)&string_velX) = vel_x;
    *((float*)&string_velY) = vel_y;
    *((float*)&string_velAng) = vel_ang;

    //reinterpret_cast<float*>(string_velX) = vel_x;
    //reinterpret_cast<float*>(string_velY) = vel_y;
    //reinterpret_cast<float*>(string_velAng) = vel_ang;

#ifndef XBEE
    // string saida foi craida com base na documentacao da biblioteca para nrf24l01 -- http://tmrh20.github.io/RF24/ //nrf24l01
    data[0] = BEGIN;  //--Padr�o
    data[1] = rf_address[0];  //--Adress
    data[2] = rf_address[1];  //--Adress
    data[3] = rf_address[2];  //--Adress
    data[4] = rf_address[3];  //--Adress
    data[5] = rf_address[4]; //--Adress
    data[6] = name; //--key
    data[7] = KEY;
    for(i=0; i<4; i++)
    {
        data[8+i]=string_velX[i];
        data[12+i]=string_velY[i];
        data[16+i]=string_velAng[i];
    }

#else
    int j = 0, address[8], aux;
    for(i=0; i<16; i++)
    {
        //--para numeros: em ascii de 48 até 57
        if(rf_address[i]>=48 && rf_address[i]<=57)
        {
            aux = rf_address[i]-48;
        }
        //--para letras: em ascii de
        if(rf_address[i]>=97 && rf_address[i]<=102)
        {
            aux = rf_address[i]-97+10;
        }
        //--para numeros pares, ele "empurra e grava"
        //--para numeros impares ele faz "ou" e grava
        if(i%2==0)
        {
            address[j]=aux<<4;
        }
        else
        {
            address[j]=address[j] | aux;
            j++;
        }
    }
    //--Fim do conversor
    // string saida foi craida com base na documentacao do Xbee S1 -- https://www.digi.com/resources/documentation/digidocs/PDFs/90000982.pdf
    data[0] = 0x7E;  //--Padrão
    data[1] = 0x00;  //--MSB length packet
    data[2] = SHIPPING_SIZE; //--LSB lenght packet
    data[3] = OP_MODE;  //--Frame type
    data[4] = UART;  //--UART to correlate with a subsequent ACK.  (Without pattern in the internet)
    data[5] = address[0];  //--MSB of adress
    data[6] = address[1];  //--Adress
    data[7] = address[2];  //--Adress
    data[8] = address[3];  //--Adress
    data[9] = address[4];  //--Adress
    data[10] = address[5]; //--Adress
    data[11] = address[6]; //--Adress
    data[12] = address[7]; //--LSB of adress
    data[13] = ACK; //--byte of options to ACK
    data[14] = KEY; //--key
    for(i=0; i<4; i++)
    {
        data[15+i]=string_velX[i];
        data[19+i]=string_velY[i];
        data[23+i]=string_velAng[i];
    }

    //--Calcular CheckSum
    aux=0;
    for(i=3; i<(PACKET_SIZE-1); i++)
    {
        aux=aux+data[i];
    }
    aux=0xff-(aux&0xff);
    data[PACKET_SIZE-1] = aux; //--Checksum
#endif
}
