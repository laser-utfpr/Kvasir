#include "Hardware.h"

Hardware::Hardware(){}

void Hardware::atualizar(EspinhaDorsal *espinhaDorsalIN){
 //--Rádio

  _comunicacao.aguardarDados();//--Aguarda contato do computador

  espinhaDorsalIN->setRadioEixoX(_comunicacao.velocidadeEixoX());//--Atualiza o campo na espinha dorsal
  espinhaDorsalIN->setRadioEixoY(_comunicacao.velocidadeEixoY());//--Atualiza o campo na espinha dorsal
  espinhaDorsalIN->setRadioVelAng(_comunicacao.velocidadeAng());
  
  //--Movimentacao
  _movimentacao.mover(espinhaDorsalIN->getMovimentacaoEixoX(), espinhaDorsalIN->getMovimentacaoEixoY(), espinhaDorsalIN->getVelAng()); //--NOTE QUE IDEPENDENDE DA ESTRATÉGIA!!! Aqui era passado a calibragem
  //_movimentacao.mover(.2, .2, _constantes.ATIVAR_CALIBRAGEM); //--NOTE QUE IDEPENDENDE DA ESTRATÉGIA!!!
  
  }
