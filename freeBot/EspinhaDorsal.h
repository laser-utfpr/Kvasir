#ifndef _ESPINHADORSAL_H_
#define _ESPINHADORSAL_H_

class EspinhaDorsal{
	private:
		//--essa secao vai guardar informacoes que vao e vem
    //--Movimentação do Robô
    float _velMovEixoX;
    float _velMovEixoY;
    float _velAng;
    
    //--Dados do Rádio
    float _velRadioEixoX;
    float _velRadioEixoY;
    float _velRadioAng;
		
	public:
	//--essa secao abrigar metodos para acessar e modificar as informaoes
	  //--Funçoes para as váriaveis do rádio
      //--Obter:
      //--Radio
      float getRadioEixoX();
      float getRadioEixoY();
      float getRadioVelAng();
      //--Movimentação
      float getMovimentacaoEixoX();
      float getMovimentacaoEixoY();
      float getVelAng();
      
      //--Escrever
      //--Radio
      void setRadioEixoX(float eixoXIN);
      void setRadioEixoY(float eixoYIN);
      void setRadioVelAng(float w);
	    //--Movimentação
      void setMovimentacaoEixoX(float eixoXIN);
      void setMovimentacaoEixoY(float eixoYIN);
      void setVelAng(float w);
	//--Construtoras e Destrutoras	
	EspinhaDorsal();
	~EspinhaDorsal(){};
};
#endif

