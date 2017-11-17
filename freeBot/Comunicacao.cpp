#include "Comunicacao.h"

Comunicacao::Comunicacao(){}
//parei aqui
void Comunicacao::aguardarDados(){
  if(_constantes.ATIVAR_TESTE == 0){
      _radio.receberRS232();
      _velocidadeEixoX = _radio.getVelX();
      _velocidadeEixoY = _radio.getVelY();
      _velAng=_radio.getVelAng();
  }//--Fim do if
  else{
      _velocidadeEixoX = _constantes.VELOCIDADE_MAXIMA;//--Seta valores fixos para fins de teste
      _velocidadeEixoY = _constantes.VELOCIDADE_MAXIMA;//--Seta valores fixos para fins de teste
      _velAng=0;
      //teste();
  }
}

float Comunicacao::velocidadeEixoX(){
  return _velocidadeEixoX;
  }
float Comunicacao::velocidadeEixoY(){
  return _velocidadeEixoY;
  }
float Comunicacao::velocidadeAng(){
  return _velAng;
}
/*void Comunicacao::teste()
{
  int direcao;
  if(Serial.available()>0)
  {
    direcao=Serial.read();
    switch(direcao)
    {
      case 'w':
      _velocidadeEixoX=0;
      _velocidadeEixoY=_constantes.VELOCIDADE_MAXIMA;
      case 'a':
      _velocidadeEixoX=-_constantes.VELOCIDADE_MAXIMA;
      _velocidadeEixoY=0;
      case 'd':
      _velocidadeEixoX=_constantes.VELOCIDADE_MAXIMA;
      _velocidadeEixoY=0;
      case 's':
      _velocidadeEixoX=0;
      _velocidadeEixoY=-_constantes.VELOCIDADE_MAXIMA;
      case 'p':
      _velocidadeEixoX=0;
      _velocidadeEixoY=0;
    }
  }
}*/

