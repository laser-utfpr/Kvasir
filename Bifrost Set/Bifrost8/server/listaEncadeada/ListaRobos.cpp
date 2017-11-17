#include "ListaRobos.h"

ListaRobos::ListaRobos()
{
    primeiroRobo = 0;
    tamanhoDaEstrutura = 0;
    roboExibido = 0;
    roboAtual=0;
}

ListaRobos::~ListaRobos()
{
    Robo* aux;
    while(primeiroRobo->getProximoRobo() != 0) //--Enquanto o primeiro objeto possuir vizinho
    {
        {
            aux = primeiroRobo->getProximoRobo();//--Pega o vizinho
            delete primeiroRobo;//--Destroi o Atual
            primeiroRobo = aux;//--vizinho assume o lugar do primeiro
            tamanhoDaEstrutura--;
        }
        delete primeiroRobo;//--Mata o ultimo que restou
        tamanhoDaEstrutura--;
    }
}

void ListaRobos::adicionarRobo(int nameIN, char* MACIN)
{
    if(primeiroRobo == 0)
    {
        primeiroRobo = new Robo(nameIN, MACIN);
        roboAtual = primeiroRobo;
        tamanhoDaEstrutura++;
    }
    else
    {
        roboAtual->setProximoRobo(new Robo(nameIN, MACIN)); //-- Aloca um robo novo
        roboAtual = roboAtual->getProximoRobo(); //-- Torna o recém criado robo como atual
        tamanhoDaEstrutura++;
    }
}

Robo* ListaRobos::percorreLista()
{
    if(roboExibido == 0)
        roboExibido = primeiroRobo;
    else
        roboExibido = roboExibido->getProximoRobo();
    return roboExibido;
}
