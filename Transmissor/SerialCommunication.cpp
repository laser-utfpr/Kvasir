#include "SerialCommunication.h"

SerialCommunication::SerialCommunication()
{
    int i;
    queue = NULL;
    for(i = 0; i< W_ADDRESS; i++)
    {
        address[i] = 0;
    }
    for(i = 0; i< W_DATA; i++)
    {
        data[i] = 0;
    }
}

int SerialCommunication::receberRS232()
{
    int i, siz;
    unsigned char a;
    siz = Serial1.available();
    if(siz>0)
    {
        for(i=0; i<siz; i++)
        {
            queue = queue->addByte(Serial1.read(), queue);
        }
        //jogar fora os caras atrasados
    
        while(queue!=NULL&&queue->getByte()!=BEGIN)
        {
            queue = queue->removeByte(queue);
        }
        if(queue->getByte()==BEGIN)
        {
            while(queue!=NULL&&queue->getSize()>(W_DATA+W_ADDRESS+1))//+1 porque o BEGIN nao entra no tamanho do pacote
            {
                queue = queue->removeByte(queue);
            }
            if(queue->getByte()!=BEGIN)
            {
                //Serial.println("ta errado");
                return 0;
            }
            else
                return 1;
        }  
    }
    else
    {
         queue = NULL;
         return 0;
    }
}

uint8_t* SerialCommunication::getAdress()
{
    int i;
    
    
    if(queue!=NULL&&queue->getByte()==BEGIN)
    {
        //Serial.print("tamanho da fila eh ");
        //Serial.println(queue->getSize());
    }
    if(queue!=NULL&&queue->getByte()==BEGIN&&queue->getSize()>=(W_DATA+W_ADDRESS))//sigmifica que tem um pacote inteiro
    {
        //Serial.print("Endereço eh: ");
        for(i=0; i<W_ADDRESS; i++)
        {
            queue = queue->removeByte(queue);
            address[i] = queue->getByte();
          //  Serial.print(char(address[i]));
        }
        queue=queue->removeByte(queue);
    }
    //Serial.println();
    return address;
}

unsigned char* SerialCommunication::getData()
{
    int i;
    while(queue!=NULL&&queue->getByte()!=KEY)
    {
        queue = queue->removeByte(queue);
    }
    if(queue!=NULL&&queue->getByte()==KEY&&queue->getSize()==(W_DATA-1))//significa que tem um pacote efetivo inteiro (-=1 pq o nome já foi adicionado)
    {
        //Serial.print("pacote inteiro: ");
        for(i=1; i<W_DATA; i++)
        {
            data[i] = queue->getByte();
            //Serial.print(data[i], HEX);
            queue = queue->removeByte(queue);
        }
        //Serial.println();
    }
    else if (queue==NULL)
    {
        data[1]=0;
    }
        
    return data;
}

char SerialCommunication::getName()
{
    if(queue->getByte()!=BEGIN)
    {
        if(queue!=NULL&&queue->getSize()==W_DATA)
        {
            //Serial.print("nome eh: ");
            //Serial.println(char(queue->getByte()));
            data[0]=queue->getByte();
            //Serial.println(data[0], HEX);
            return (data[0]);
        }
    }
    //return static_cast <char> (-1);
  //  Serial.println();
}
