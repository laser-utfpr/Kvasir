#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_

#include <unistd.h>
#include "listaEncadeada/ListaRobos.h"
#include "relacaoRobos/RelacaoRobos.h"
#include "listaEncadeada/Robo.h"
#include "radio/Radio.h"
#include "radio/SerialPacket.h"
#include <string>
#include <iostream>
#include <smmclib.hpp>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/allocators/allocator.hpp>

class Principal{
private:
    ListaRobos* vetorRobos;
    RelacaoRobos* arquivo;
    Robo* robo_acessado;
    Radio* radio;
    SerialPacket* packet;

    std::string chave_escrita;
    std::string chave_leitura;
    std::string chave_desligamento;

    boost::interprocess::managed_shared_memory *memoria_compartilhada;

    void checarRobosAtivos();
    void carregarRobos();
    void transmitir();

public:
    Principal(const char* arg1, const char* arg2, const char* arg3);
    ~Principal();
};
#endif
