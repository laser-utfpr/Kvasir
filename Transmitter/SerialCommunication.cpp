#include "SerialCommunication.h"

SerialCommunication::SerialCommunication()
{
    int i;
    //queue = NULL;
    for(i = 0; i< W_ADDRESS; i++)
    {
        address[i] = 0;
    }
    for(i = 0; i< W_DATA; i++)
    {
        data[i] = 0;
    }
    for(i = 0; i<W_DATA+W_ADDRESS+1; i++)
    {
        received_data[i] = 0;
    }
}

int SerialCommunication::receiveRS232()
{
    int i, siz;
    siz = Serial1.readBytes(received_data, W_DATA+W_ADDRESS+1);
    Serial1.flush();
    //delayMicroseconds(500);
    if(siz==W_DATA+W_ADDRESS+1 && received_data[0] == BEGIN)
    {
        return 1;
        /*for(i=0; i<siz; i++)
        {
            queue = queue->addByte(data[i], queue);

            //Serial.print(data[i], HEX);
        }
        
        //Serial.println();
        if(queue!=NULL && queue->getSize() < (W_DATA+W_ADDRESS+1))
        {
            //Serial.print("pacote errado: ");
            //Serial.print(queue->getSize());
            //Serial.println(siz);
            return 0;
        }
        //jogar fora os caras atrasados

        while(queue!=NULL&&queue->getByte()!=BEGIN)
        {
            //Serial.print(" remove ");
            //Serial.print(queue->getByte(), HEX);
            queue = queue->removeByte(queue);
        }
        //Serial.println();
        if(queue!=NULL && queue->getByte()==BEGIN)
        {
            while(queue!=NULL&&queue->getSize()>(W_DATA+W_ADDRESS+1))//+1 porque o BEGIN nao entra no tamanho do pacote
            {
                queue = queue->removeByte(queue);
            }
            if(queue!=NULL&&queue->getByte()!=BEGIN)
            {
                //Serial.println("ta errado");
                return 0;
            }
            else
                return 1;
        }*/
    }
    else
    {
         return 0;
    }
}

void SerialCommunication::getAddress(uint8_t *_address)
{
    int i;


    /*if(queue!=NULL&&queue->getByte()==BEGIN)
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
            //Serial.print(char(address[i]));
        }
        queue=queue->removeByte(queue);
    }*/
    for(i=0; i<W_ADDRESS; i++)
    {
        address[i] = received_data[i+1];
    }
    for(i=0; i<W_ADDRESS; i++)
    {
        _address[i] = address[i];
    }
    
    //Serial.println();
    //_address = address;
}

void SerialCommunication::getData(unsigned char *_data)
{
    int i;
    /*while(queue!=NULL&&queue->getByte()!=KEY)
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
    }*/
    for(i=1; i<W_DATA; i++)
    {
        data[i] = received_data[i+1+W_ADDRESS];
    }
    for(i=0; i<W_DATA; i++)
    {
        
        
        _data[i] = data[i];
    }
    //queue = NULL;
    //*_data = data;
    //return data;
}

char SerialCommunication::getName()
{
    data[0] = received_data[1+W_ADDRESS];
    return data[0];
    /*if(queue!=NULL && queue->getByte()!=BEGIN)
    {
        if(queue!=NULL&&queue->getSize()==W_DATA)
        {
            //Serial.print("nome eh: ");
            //Serial.println(char(queue->getByte()));
            data[0]=queue->getByte();
            //Serial.println(data[0], HEX);
            return (data[0]);
        }
    }*/
    
    //return static_cast <char> (-1);
  //  Serial.println();
}
