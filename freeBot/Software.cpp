#include "Software.h"

Software::Software()
{
    tempo=0;
}

void Software::atualizar(EspinhaDorsal *espinhaDorsalIN)
{
    //--As seguintes funções espelham o recebido pelo rádio para os motores
    if(ATIVAR_TESTE == 1)
    {
        teste(espinhaDorsalIN);
    }
    else
    {
        espinhaDorsalIN->setMovimentacaoEixoX(espinhaDorsalIN->getRadioEixoX());
        espinhaDorsalIN->setMovimentacaoEixoY(espinhaDorsalIN->getRadioEixoY());
        espinhaDorsalIN->setVelAng(espinhaDorsalIN->getRadioVelAng());
    }
}

void Software::teste(EspinhaDorsal *espinhaDorsalIN)
{
    int aux;
    aux = millis()-tempo;
    if(aux < 5000)
    {
        Serial.println("x = 0 e y = 0");
        espinhaDorsalIN->setMovimentacaoEixoX(0);
        espinhaDorsalIN->setMovimentacaoEixoY(0);
        espinhaDorsalIN->setVelAng(0);
    }
    else if(aux > 5000 && aux < 7500)
    {
        Serial.println("x = 1 e y = 0");
        espinhaDorsalIN->setMovimentacaoEixoX(VELOCIDADE_MAXIMA);
        espinhaDorsalIN->setMovimentacaoEixoY(0);
        espinhaDorsalIN->setVelAng(0);
    }
    else if(aux > 7500 && aux < 10000)
    {
        Serial.println("x = -1 e y = 0");
        espinhaDorsalIN->setMovimentacaoEixoX(-VELOCIDADE_MAXIMA);
        espinhaDorsalIN->setMovimentacaoEixoY(0);
        espinhaDorsalIN->setVelAng(0);
    }
    else if(aux > 10000 && aux < 12500)
    {
        Serial.println("x = 0 e y = 1");
        espinhaDorsalIN->setMovimentacaoEixoX(0);
        espinhaDorsalIN->setMovimentacaoEixoY(VELOCIDADE_MAXIMA);
        espinhaDorsalIN->setVelAng(0);
    }
    else if(aux > 12500 && aux < 15000)
    {
        Serial.println("x = 0 e y = -1");
        espinhaDorsalIN->setMovimentacaoEixoX(0);
        espinhaDorsalIN->setMovimentacaoEixoY(-VELOCIDADE_MAXIMA);
        espinhaDorsalIN->setVelAng(0);
    }
    else if(aux > 15000 && aux < 17500)
    {
        Serial.println("x = 1 e y = 1");
        espinhaDorsalIN->setMovimentacaoEixoX(VELOCIDADE_MAXIMA);
        espinhaDorsalIN->setMovimentacaoEixoY(VELOCIDADE_MAXIMA);
        espinhaDorsalIN->setVelAng(0);
    }
    else if(aux > 17500 && aux < 20000)
    {
        Serial.println("x = 1 e y = -1");
        espinhaDorsalIN->setMovimentacaoEixoX(VELOCIDADE_MAXIMA);
        espinhaDorsalIN->setMovimentacaoEixoY(-VELOCIDADE_MAXIMA);
        espinhaDorsalIN->setVelAng(0);
    }
    else if(aux > 20000 && aux < 22500)
    {
        Serial.println("x = -1 e y = 1");
        espinhaDorsalIN->setMovimentacaoEixoX(-VELOCIDADE_MAXIMA);
        espinhaDorsalIN->setMovimentacaoEixoY(VELOCIDADE_MAXIMA);
        espinhaDorsalIN->setVelAng(0);
    }
    else if(aux > 22500 && aux < 25000)
    {
        Serial.println("x = -1 e y = -1");
        espinhaDorsalIN->setMovimentacaoEixoX(-VELOCIDADE_MAXIMA);
        espinhaDorsalIN->setMovimentacaoEixoY(-VELOCIDADE_MAXIMA);
        espinhaDorsalIN->setVelAng(0);
    }

    else if(aux > 25000)
    {
        tempo = millis();
    }

}
