#ifndef _MOVIMENTACAO_H_
#define _MOVIMENTACAO_H_

#include <math.h> 
#include "Constantes.h"
#include "ServoRotativo.h"

struct VelocidadeDosMotores{
  float motor1;
  float motor2;
  float motor3;
  float motor4;
  };

class Movimentacao{
    private:
        Constantes _constantes;
        Pinagem _pinagem;
        ServoRotativo _motor1;
        ServoRotativo _motor2;
        ServoRotativo _motor3;
        ServoRotativo _motor4;
    
        void _calculo(float velXIN, float velYIN, float w);
	      VelocidadeDosMotores _velocidade; 
	
    public:
	//--Métodos:
        void mover(float velXIN, float velYIN, float w);
 	
	//--Construtoras e Destrutoras	
	Movimentacao();
	~Movimentacao(){};
};
#endif

