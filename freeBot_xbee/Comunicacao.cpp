#include "Comunicacao.h"

Comunicacao::Comunicacao()
{
    radio = new XbeeRobo();
}

int Comunicacao::aguardarDados(int captar)
{
    int fim;
    if(ATIVAR_TESTE == 0)
    {
        if(captar == 1)
        {
            radio->receberRS232();
        }
        fim = radio->atualizarBuffer(); //retorna 1 quando o Buffer local estiver sem pacotes completos
        velocidadeEixoX = radio->getVelX();
        velocidadeEixoY = radio->getVelY();
        velAng = radio->getVelAng();
    }
    return fim;
}

float Comunicacao::getVelocidadeEixoX()
{
    return velocidadeEixoX;
}

float Comunicacao::getVelocidadeEixoY()
{
    return velocidadeEixoY;
}

float Comunicacao::getVelocidadeAng()
{
    return velAng;
}

