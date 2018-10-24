#include "ListaRobos.h"

ListaRobos::ListaRobos()
{
    primeiroRobo = NULL;
    tamanhoDaEstrutura = 0;
    roboExibido = NULL;
    roboAtual=NULL;
}

ListaRobos::~ListaRobos()
{
    Robo* aux;
    while(primeiroRobo->getProximoRobo() != NULL) //--Enquanto o primeiro objeto possuir vizinho
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
    if(primeiroRobo == NULL)
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
    if(roboExibido == NULL)
        roboExibido = primeiroRobo;
    else
        roboExibido = roboExibido->getProximoRobo();
    return roboExibido;
}
