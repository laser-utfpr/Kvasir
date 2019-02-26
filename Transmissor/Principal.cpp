#include "Principal.h"

Principal::Principal()
{
    serial = new SerialCommunication(); //comunicacao Serial1
	  rWriter = new RadioWriter(); //envio de dados
}

void Principal::PrincipalStart()
{
    uint8_t* address;
    char name;
	  while(1)
	  {
        if(serial->receberRS232())
        {
            address=serial->getAddress();
            name = serial->getName();
            //Serial.print("nome eh: ");
            //Serial.print((int)name);
            //Serial.print(" ende eh: ");
            //Serial.println((char)address[4]);
            rWriter->setChannel(name);
		        rWriter->setAddress(address);
		        rWriter->sendData(serial->getData());
            //rWriter.debug();
        }
   		    //delay(1000);
    }
}
