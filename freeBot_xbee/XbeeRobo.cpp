#include "XbeeRobo.h"

XbeeRobo::XbeeRobo()
{
    velocidadeY = 0;
    velocidadeX = 0;
    velAng = 0;
    queue = NULL;
}

void XbeeRobo::receberRS232()
{
    int i, siz;
    siz = Serial.available();
    if(siz>0)
    {
        for(i=0; i<siz; i++)
        {
            queue = queue->addByte(Serial.read(), queue);
        }
    }
}

int XbeeRobo::atualizarBuffer()
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
        Serial.println(velocidadeX);
    }
    if(queue!=NULL&&queue->getSize()>(DADOS+1))//significa que ainda tem um pacote inteiro a ser lido, nesse caso nao se verifica o Buffer do arduino ate que o Buffer local seja totalmente usado
    {
        return 0;
    }
    return 1;
}

float XbeeRobo::getVelY()
{
    return velocidadeY;
}

float XbeeRobo::getVelX()
{
    return velocidadeX;
}
float XbeeRobo::getVelAng()
{
    return velAng;
}

