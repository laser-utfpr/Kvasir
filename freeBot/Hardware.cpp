#include "Hardware.h"

Hardware::Hardware()
{
    comunicacao = Comunicacao();
<<<<<<< HEAD
    movimentacao = new Movimentacao();
=======
    movimentacao = Movimentacao();
>>>>>>> cb7f1da065620fe6ff221ce749a10261c0cfc086
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
