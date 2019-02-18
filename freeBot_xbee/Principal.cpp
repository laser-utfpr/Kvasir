#include "Principal.h"

void PrincipalStart()
{
	   Hardware* hardware = new Hardware();//--Corpo do Robo
     Software* software = new Software();//--Estrategia do Robo
     EspinhaDorsal* espinhaDorsal = new EspinhaDorsal();//--Comunicação das princiopais classes
	   //--O metodo espinha dorsal eh dividido em dois
        //--1) O metodo sem atributos retorna o ponteiro de uma classe chamada EspinhaDorsal
      //--2) O metodo que recebe  atriutos recebe o ponteiro de uma classe  chamada EspinhaDorsal
     //--A EspinhaDorsal ira realizar a comunicacao entre Estrategia e Eletronica.
	   while(1)
	   {
				    hardware->atualizar(espinhaDorsal);//--Verifica e modifica dados novos no hardware
            software->atualizar(espinhaDorsal);//--Verifica e modifica dados novos na Estrategia
 
		        delay(330); 
	   }
     /* Caso se resolva desligar o arduino de alguma maneira
     delete hardware;
     delete software;
     delete espinhaDorsal;
     */
}

