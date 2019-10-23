#include "Principal.h"

Principal::Principal()
{
    serial = new SerialCommunication(); //comunicacao Serial1
    rWriter = new RadioWriter(); //envio de dados
}

void Principal::start()
{
    uint8_t address[W_ADDRESS];
    unsigned char data[W_DATA];
    char name;
    long time = millis();
    int qt = 0;
	  while(1)
	  {
        if(serial->receiveRS232())
        {
            digitalWrite(13, HIGH);
            serial->getAddress(address);
            name = serial->getName();
            if(name == 0)
            {
              //Serial.print("nome eh: ");
              //Serial.print((int)name);
              //Serial.print(" ende eh: ");
              //Serial.println((char)address[4]);
              qt++;
            }
            //rWriter->setChannel(name);
	          rWriter->setAddress(address);
            serial->getData(data);
	          rWriter->sendData(data);
            //rWriter.debug();
            //qt++;
        }
        else
        {
            digitalWrite(13, LOW);
        }
        if(millis()-time >=1000)
        {
            Serial.println(qt);
            time = millis();
            qt = 0;
        }
   		    //delay(1000);
    }
}
