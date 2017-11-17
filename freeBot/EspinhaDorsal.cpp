#include "EspinhaDorsal.h"
//--Construtora
EspinhaDorsal::EspinhaDorsal(){}
//--Variáveis do Rádio
   //--Obter:
   //--Radio
      float EspinhaDorsal::getRadioEixoX(){
        return _velRadioEixoX;
        }
      float EspinhaDorsal::getRadioEixoY(){
        return _velRadioEixoY;
        }
      float EspinhaDorsal::getRadioVelAng(){
        return _velRadioAng;
      }
   //--Movimentaçao
      float EspinhaDorsal::getMovimentacaoEixoX(){
        return _velMovEixoX;
        }
      float EspinhaDorsal::getMovimentacaoEixoY(){
        return _velMovEixoY;
        }
        float EspinhaDorsal::getVelAng(){
          return _velAng;
        }
   //--Escrever
//--Radio:
      void EspinhaDorsal::setRadioEixoX(float eixoXIN){
        _velRadioEixoX=eixoXIN;
        }
      void EspinhaDorsal::setRadioEixoY(float eixoYIN){
        _velRadioEixoY=eixoYIN;
        }
      void EspinhaDorsal::setRadioVelAng(float w){
        _velRadioAng=w;  
      }
//--Movimentação:
      void EspinhaDorsal::setMovimentacaoEixoX(float eixoXIN){
        _velMovEixoX=eixoXIN;
        }
      void EspinhaDorsal::setMovimentacaoEixoY(float eixoYIN){
        _velMovEixoY=eixoYIN;
        }
      void EspinhaDorsal::setVelAng(float w){
        _velAng=w;
      } 
		
