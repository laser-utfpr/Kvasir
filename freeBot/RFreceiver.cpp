#include "RFreceiver.h"

RFreceiver::RFreceiver()
{
    velocidadeY = 0;
    velocidadeX = 0;
    velAng = 0;
    queue = NULL;
    radio = new Radio();
    uint8_t address[] = {ADDRESS};
    radio->openReadingPipe(1, address);
    radio->startListening();
}

int RFreceiver::receber()
{
    int i, a=0;
    unsigned char data[W_DATA];

    if(radio->available())
    {
        radio->read(&data,W_DATA);
        if(data[0]==NAME&&data[1]!=0)
        {
           // Serial.print("Data recebida: ");
            for(i=0; i<W_DATA; i++)
            {
                queue = queue->addByte(data[i], queue);
           //     Serial.print(data[i], HEX);
           //     Serial.print("  ");
            }
            a++;
        }
        else
            queue = NULL;
       // Serial.println();
    }
    //else
      //  Serial.println("erro");
    return a;
}

int RFreceiver::atualizarBuffer()
{
    unsigned char byte_entrada[DADOS];
    int i;
    while(queue!=NULL&&queue->getByte()!=KEY)
    {
        queue = queue->removeByte(queue);
    }
    if(queue!=NULL&&queue->getByte()==KEY&&queue->getSize()>DADOS)//mudar isso, passar para constantes
    {
        for(i=0; i<DADOS; i++)
        {
            queue = queue->removeByte(queue);
            byte_entrada[i] = queue->getByte();
        }
	//estas operacoes convertem 4 char em 1 float
        velocidadeX = *(float*)&byte_entrada[0];
        velocidadeY = *(float*)&byte_entrada[4];
        velAng = *(float*)&byte_entrada[8];
    }
    if(queue!=NULL&&queue->getSize()>(DADOS+1))//significa que ainda tem um pacote inteiro a ser lido, nesse caso nao se verifica o Buffer do arduino ate que o Buffer local seja totalmente usado
    {
        return 0;
    }
    return 1;
}

void RFreceiver::debug()
{
    radio->printDetails();
}

float RFreceiver::getVelY()
{
    return velocidadeY;
}

float RFreceiver::getVelX()
{
    return velocidadeX;
}
float RFreceiver::getVelAng()
{
    return velAng;
}
