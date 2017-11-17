#ifndef _SOFTWARE_H_
#define _SOFTWARE_H_
#include "Constantes.h"
#include "EspinhaDorsal.h"
#include <Arduino.h>
class Software{
	private:
		//EspinhaDorsal _espinhaDorsal;
                Constantes _constantes;	
                unsigned long _tempo;
                void _teste(EspinhaDorsal *espinhaDorsalIN);
	public:
	//--Funcoes de Estrategia
	
	//--Comunicacao com o HardWare
		void atualizar(EspinhaDorsal *espinhaDorsalIN);
		
	//--Construtoras e Destrutoras	
	Software();
	~Software(){};
};
#endif

    
