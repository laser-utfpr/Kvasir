#include "Software.h"

Software::Software(){
  _tempo=0;
}
void Software::atualizar(EspinhaDorsal *espinhaDorsalIN){
  //--As seguintes funções espelham o recebido pelo rádio para os motores
  
  if(_constantes.ATIVAR_TESTE == 1){         
        _teste(espinhaDorsalIN);
  }
  else{
        espinhaDorsalIN->setMovimentacaoEixoX(espinhaDorsalIN->getRadioEixoX());
        espinhaDorsalIN->setMovimentacaoEixoY(espinhaDorsalIN->getRadioEixoY());
        espinhaDorsalIN->setVelAng(espinhaDorsalIN->getRadioVelAng());
  }
}
  
void Software::_teste(EspinhaDorsal *espinhaDorsalIN){
 /* int direcao;
  if(Serial.available()>0)
  {
    Serial.print("entrei");
    direcao=Serial.read();
    switch(direcao)
    {
      case 'w':
       espinhaDorsalIN->setMovimentacaoEixoX(0);
       espinhaDorsalIN->setMovimentacaoEixoY(_constantess.VELOCIDADE_MAXIMA);
      case 'a':
       espinhaDorsalIN->setMovimentacaoEixoX(-_constantess.VELOCIDADE_MAXIMA);
    espinhaDorsalIN->setMovimentacaoEixoY(0);
      case 'd':
       espinhaDorsalIN->setMovimentacaoEixoX(_constantess.VELOCIDADE_MAXIMA);
    espinhaDorsalIN->setMovimentacaoEixoY(0);
      case 's':
       espinhaDorsalIN->setMovimentacaoEixoX(0);
    espinhaDorsalIN->setMovimentacaoEixoY(-_constantess.VELOCIDADE_MAXIMA);
      case 'p':
       espinhaDorsalIN->setMovimentacaoEixoX(0);
    espinhaDorsalIN->setMovimentacaoEixoY(0);
    }
  }*/
  int aux;
  aux = millis()-_tempo;  
  if(aux < 5000){
    Serial.println("x = 0 e y = 0");
    espinhaDorsalIN->setMovimentacaoEixoX(0);
    espinhaDorsalIN->setMovimentacaoEixoY(0);
    espinhaDorsalIN->setVelAng(0);
  }
  else if(aux > 5000 && aux < 7500){
    Serial.println("x = 1 e y = 0");
    espinhaDorsalIN->setMovimentacaoEixoX(_constantes.VELOCIDADE_MAXIMA);
    espinhaDorsalIN->setMovimentacaoEixoY(0);
    espinhaDorsalIN->setVelAng(0);
}
  else if(aux > 7500 && aux < 10000){
    Serial.println("x = -1 e y = 0");
    espinhaDorsalIN->setMovimentacaoEixoX(-_constantes.VELOCIDADE_MAXIMA);
    espinhaDorsalIN->setMovimentacaoEixoY(0);             
    espinhaDorsalIN->setVelAng(0);
}
  else if(aux > 10000 && aux < 12500){
    Serial.println("x = 0 e y = 1");
    espinhaDorsalIN->setMovimentacaoEixoX(0);
    espinhaDorsalIN->setMovimentacaoEixoY(_constantes.VELOCIDADE_MAXIMA);  
    espinhaDorsalIN->setVelAng(0);     
}
  else if(aux > 12500 && aux < 15000){
    Serial.println("x = 0 e y = -1");
    espinhaDorsalIN->setMovimentacaoEixoX(0);
    espinhaDorsalIN->setMovimentacaoEixoY(-_constantes.VELOCIDADE_MAXIMA); 
    espinhaDorsalIN->setVelAng(0);       
}
  else if(aux > 15000 && aux < 17500){
    Serial.println("x = 1 e y = 1");
    espinhaDorsalIN->setMovimentacaoEixoX(_constantes.VELOCIDADE_MAXIMA);
    espinhaDorsalIN->setMovimentacaoEixoY(_constantes.VELOCIDADE_MAXIMA);
    espinhaDorsalIN->setVelAng(0);
}
  else if(aux > 17500 && aux < 20000){
    Serial.println("x = 1 e y = -1");
    espinhaDorsalIN->setMovimentacaoEixoX(_constantes.VELOCIDADE_MAXIMA);
    espinhaDorsalIN->setMovimentacaoEixoY(-_constantes.VELOCIDADE_MAXIMA);  
    espinhaDorsalIN->setVelAng(0);      
}
  else if(aux > 20000 && aux < 22500){
    Serial.println("x = -1 e y = 1");
    espinhaDorsalIN->setMovimentacaoEixoX(-_constantes.VELOCIDADE_MAXIMA);
    espinhaDorsalIN->setMovimentacaoEixoY(_constantes.VELOCIDADE_MAXIMA);  
    espinhaDorsalIN->setVelAng(0);      
}
  else if(aux > 22500 && aux < 25000){
    Serial.println("x = -1 e y = -1");
    espinhaDorsalIN->setMovimentacaoEixoX(-_constantes.VELOCIDADE_MAXIMA);
    espinhaDorsalIN->setMovimentacaoEixoY(-_constantes.VELOCIDADE_MAXIMA);   
    espinhaDorsalIN->setVelAng(0);   
}

  else if(aux > 25000){
    _tempo = millis(); 
}            
       
}
