#ifndef _HARDWARE_H_
#define _HARDWARE_H_

#include "Comunicacao.h"
#include "Movimentacao.h"

#include "Constantes.h"
#include "EspinhaDorsal.h"

class Hardware{
	private:
		//EspinhaDorsal _espinhaDorsal;//--comunicação entre o software e o hardware
		Comunicacao _comunicacao;  //--Abriga o modulo xbee e a serial
		Movimentacao _movimentacao;//--Abriga os motores e os calculos
                Constantes _constantes;//--Abriga todas as constantes do sistema
		
	
	public:
	//--Comunicacao com o Software
		void atualizar(EspinhaDorsal *espinhaDorsalIN);
		
	//--Construtoras e Destrutoras	
	Hardware();
	~Hardware(){};
};
#endif
