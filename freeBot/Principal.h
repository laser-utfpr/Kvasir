#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_


//--Bibliotecas
#include <Arduino.h>

//--Classes
#include "Hardware.h"
#include "Software.h"
#include "EspinhaDorsal.h"
class Principal{
	private:
		Hardware hardware;//--Corpo do Robo
		Software software;//--Estrategia do Robo
    EspinhaDorsal espinhaDorsal;//--Comunicação das princiopais classes
	public:
                Principal();
		~Principal(){};
};
#endif
