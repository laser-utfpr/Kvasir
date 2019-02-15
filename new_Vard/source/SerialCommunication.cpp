#include "SerialCommunication.hpp"

SerialCommunication::SerialCommunication()
{
    if(RS232_OpenComport(CPORT_NR, BDRATE, "8N1"))
    {
        printf("AVISO: NENHUMA serial encontrada!!\n");
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
}
