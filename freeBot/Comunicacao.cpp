#include "Comunicacao.h"

Comunicacao::Comunicacao()
{
    rReceiver = RFreceiver();
    a=0;
    tempo=0;
    aux=0;
}

int Comunicacao::aguardarDados(int captar)
{
    int buffer_vazio = 0;
    if(ATIVAR_TESTE == 0)
    {
        if(captar == 1)
        {
            a+=rReceiver.receber();
            aux = millis()-tempo;
            if(aux >= 27000)
            {
                Serial.print("media/s: ");
                a=a/30;
                Serial.println(a);
                a=0;
                tempo = millis();
            }
            //Serial.print(*a);
        }
        buffer_vazio = rReceiver.atualizarBuffer(); //retorna 1 quando o Buffer local estiver sem pacotes completos
        velocidadeEixoX = rReceiver.getVelX();
        velocidadeEixoY = rReceiver.getVelY();
        velAng = rReceiver.getVelAng();
        //rReceiver->debug();
    }
    return buffer_vazio;
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
