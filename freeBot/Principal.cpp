#include "Principal.h"

#include <Arduino.h>

Principal::Principal(){
	while(1){

		//--O metodo espinha dorsal eh dividido em dois
		    //--1) O metodo sem atributos retorna o ponteiro de uma classe chamada EspinhaDorsal
			//--2) O metodo que recebe  atriutos recebe o ponteiro de uma classe  chamada EspinhaDorsal
		//--A EspinhaDorsal ira realizar a comunicacao entre Estrategia e Eletronica.
		software.atualizar(&espinhaDorsal);//--Verifica e modifica dados novos na Estrategia
    hardware.atualizar(&espinhaDorsal);//--Verifica e modifica dados novos no hardware
                //--Serial.println("Espinha");Serial.println(espinhaDorsalIN->getMovimentacaoEixoX());Serial.println(espinhaDorsalIN->getMovimentacaoEixoY());           
		delay(100); //--Pausa para estabilizar a comunicacao. 
	}
}
