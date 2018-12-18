#include "Hardware.h"

Hardware::Hardware()
{
    comunicacao = Comunicacao();
    movimentacao = Movimentacao();
}

void Hardware::atualizar(EspinhaDorsal *espinhaDorsal)
{
    int captar = 1;
    captar = comunicacao.aguardarDados(captar);

    espinhaDorsal->setRadioEixoX(comunicacao.getVelocidadeEixoX());
    espinhaDorsal->setRadioEixoY(comunicacao.getVelocidadeEixoY());
    espinhaDorsal->setRadioVelAng(comunicacao.getVelocidadeAng());

    movimentacao.mover(espinhaDorsal->getMovimentacaoEixoX(), espinhaDorsal->getMovimentacaoEixoY(), espinhaDorsal->getVelAng());

    while(captar == 0 && !ATIVAR_TESTE)
    {
        captar = comunicacao.aguardarDados(captar);

        espinhaDorsal->setRadioEixoX(comunicacao.getVelocidadeEixoX());
        espinhaDorsal->setRadioEixoY(comunicacao.getVelocidadeEixoY());
        espinhaDorsal->setRadioVelAng(comunicacao.getVelocidadeAng());

        movimentacao.mover(espinhaDorsal->getMovimentacaoEixoX(), espinhaDorsal->getMovimentacaoEixoY(), espinhaDorsal->getVelAng());

    }
}
