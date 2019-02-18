#include "EspinhaDorsal.h"

float EspinhaDorsal::getRadioEixoX()
{
    return velRadioEixoX;
}

float EspinhaDorsal::getRadioEixoY()
{
    return velRadioEixoY;
}

float EspinhaDorsal::getRadioVelAng()
{
    return velRadioAng;
}

float EspinhaDorsal::getMovimentacaoEixoX()
{
    return velMovEixoX;
}

float EspinhaDorsal::getMovimentacaoEixoY()
{
    return velMovEixoY;
}

float EspinhaDorsal::getVelAng()
{
    return velAng;
}


void EspinhaDorsal::setRadioEixoX(float velX)
{
    velRadioEixoX=velX;
}

void EspinhaDorsal::setRadioEixoY(float velY)
{
    velRadioEixoY=velY;
}

void EspinhaDorsal::setRadioVelAng(float w)
{
    velRadioAng=w;
}

void EspinhaDorsal::setMovimentacaoEixoX(float velX)
{
    velMovEixoX=velX;
}

void EspinhaDorsal::setMovimentacaoEixoY(float velY)
{
    velMovEixoY=velY;
}

void EspinhaDorsal::setVelAng(float w)
{
    velAng=w;
}

