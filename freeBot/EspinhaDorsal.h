//biblioteca responsavel por fazer comunicacao entre software e hardware. Todas as funcoes sao basicas, apenas receber e enviar dados

#ifndef _ESPINHADORSAL_H_
#define _ESPINHADORSAL_H_

class EspinhaDorsal{
private:
    //--essa secao vai guardar informacoes que vao e vem
    //--Movimentação do Robô
    float velMovEixoX;
    float velMovEixoY;
    float velAng;

    //--Dados do Rádio
    float velRadioEixoX;
    float velRadioEixoY;
    float velRadioAng;

public:
    EspinhaDorsal() {};
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
    void setRadioEixoX(float velX);
    void setRadioEixoY(float velY);
    void setRadioVelAng(float w);
    //--Movimentação
    void setMovimentacaoEixoX(float velX);
    void setMovimentacaoEixoY(float velY);
    void setVelAng(float w);

    ~EspinhaDorsal() {};
};
#endif

