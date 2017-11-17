#ifndef _COMUNICACAO_H_
#define _COMUNICACAO_H_

#include"XbeeRobo.h"
#include "Constantes.h"

class Comunicacao{
	private:
    Constantes _constantes;
    XbeeRobo _radio;
    float _velocidadeEixoX;
    float _velocidadeEixoY;
    float _velAng;
	public:
  //--Obter Dados recebidos:
      float velocidadeEixoX();
      float velocidadeEixoY();
      float velocidadeAng();
      void aguardarDados();
      //void teste();
	//--Construtoras e Destrutoras
	Comunicacao();
	~Comunicacao(){};
};
#endif
