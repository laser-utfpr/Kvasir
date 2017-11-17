#include "Principal.h"
Principal::Principal()
{
    display = new Display();
    vetorRobos = new ListaRobos();
    arquivo = new RelacaoRobos();
    radio = new Radio();
    xbee = new XbeeAPI();
    carregarRobos();
    display->addLineStatus("O programa Esta travado com hex fixos!!");
    while(1)
    {
        checarRobosAtivos();
        transmitir();
        display->print();
    }
}

void Principal::checarRobosAtivos()
{
    char auxDisplay[300];
    sprintf(auxDisplay,"Robo\t|Endereco MAC\t|Velocidade X\t|Velocidade Y\t|Velocidade Ang\t|Escrito por\t|");
    display->addLineRobos(auxDisplay);

    acessado = vetorRobos->percorreLista();
    while(acessado != 0)
    {
        sprintf(auxDisplay,"%d\t| %s\t| %.2fm/s\t| %.2fm/s\t| %.2fangs/s\t|%s\t|", acessado->getNome(), acessado->getMAC(), acessado->getVelX(), acessado->getVelY(), acessado->getVelAng(), acessado->getProcessName());
        display->addLineRobos(auxDisplay);
        acessado = vetorRobos->percorreLista();
    }
}

void Principal::transmitir()
{
    unsigned char *auxXbee;
    char auxDisplay[300];
    char auxDisplay1[300];
    acessado = vetorRobos->percorreLista();
    while(acessado != 0)
    {
        sprintf(auxDisplay,"Transmitindo para %s\t: Vx:%.2fm/s, Vy:%.2fm/s %.2fangm/s", acessado->getMAC(),
                acessado->getVelX(), acessado->getVelY(), acessado->getVelAng());
        auxXbee = xbee->montarPacoteRS232(acessado->getMAC(), acessado->getVelX(), acessado->getVelY(), 0x00, 0);
        radio->send(auxXbee);
        usleep(10000);

        sprintf(auxDisplay,"Transmitindo para '%d' com MAC '%s' o pacote ", acessado->getNome(),acessado->getMAC());
        sprintf(auxDisplay1," %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x",
                auxXbee[14] & 0xff, auxXbee[15] & 0xff, auxXbee[16] & 0xff, auxXbee[17] & 0xff, auxXbee[18] & 0xff,
                auxXbee[19] & 0xff, auxXbee[20] & 0xff, auxXbee[21] & 0xff, auxXbee[22] & 0xff, auxXbee[23] & 0xff,
                auxXbee[24] & 0xff, auxXbee[25] & 0xff, auxXbee[26] & 0xff, auxXbee[27] & 0xff);

        strcat(auxDisplay,auxDisplay1);
        display->addLineRadio(auxDisplay);
        acessado = vetorRobos->percorreLista();
    }
}

void Principal::carregarRobos()
{
    char  auxDisplay[300];
    while (arquivo->getNextLine() != 0)
    {
        vetorRobos->adicionarRobo(arquivo->getNumero(), arquivo->getMAC());
        sprintf(auxDisplay,"Robo numero %d com o MAC ADDRESS %s foi adicionado!",arquivo->getNumero(), arquivo->getMAC());
        display->addLineStatus(auxDisplay);
    }
}
Principal::~Principal() {}
