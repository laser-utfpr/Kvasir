#include "Principal.h"

Principal::Principal()
{
	serial = SerialCommunication(); //comunicacao Serial1
	rWriter = RadioWriter(); //envio de dados
}

void Principal::PrincipalStart()
{
     uint8_t* adress;
     char name;
	   while(1)
	   {
  		  if(serial.receberRS232())
        {
  			    adress=serial.getAddress();
            name = serial.getName();
            rWriter.setChannel(name);
  			    rWriter.setAddress(adress);
  			    rWriter.sendData(serial.getData());
            //rWriter.debug();
        }

   		    //delay(1000);
  	   }
}
