#include "Principal.h"

Principal::Principal(const char* arg1, const char* arg2, const char* arg3):
chave_escrita(arg1), chave_leitura(arg2), chave_desligamento(arg3)
{
    vetorRobos = new ListaRobos();
    arquivo = new RelacaoRobos();
    radio = new Radio();
    packet = new SerialPacket();
    robo_acessado = NULL;
    carregarRobos();

    try
    {
        memoria_compartilhada = new boost::interprocess::managed_shared_memory(boost::interprocess::open_only,
                                                                       SHARED_MEMORY_BLOCK_NAME);
    }
    catch(const std::exception& e)
    {
        std::cout << std::endl << "Exception called while opening shared memory block:" << std::endl;
        std::cout << e.what() << std::endl;
        exit(1);
    }

    BoostInterprocessString *chave_escrita_mem;
    BoostInterprocessString *chave_leitura_mem;
    BoostInterprocessString *chave_desligamento_mem;
    try
    {
        chave_escrita_mem = (memoria_compartilhada->find<BoostInterprocessString>(COMM_WRITE_KEY_MEMORY_NAME)).first;
        chave_leitura_mem = (memoria_compartilhada->find<BoostInterprocessString>(COMM_READ_KEY_MEMORY_NAME)).first;
        chave_desligamento_mem = (memoria_compartilhada->find<BoostInterprocessString>(COMM_SHUTDOWN_KEY_MEMORY_NAME)).first;
    }
    catch(const std::exception& e)
    {
        std::cout << std::endl << "Exception called while acessing shared memory keys:" << std::endl;
        std::cout << e.what() << std::endl;
        exit(1);
    }
    while(*chave_desligamento_mem != chave_desligamento.c_str())
    {
        //if(*chave_leitura_mem == chave_leitura.c_str())
        {
            //*chave_leitura_mem = EMPTY_KEY;
            checarRobosAtivos();
            transmitir();
        }
    }
}

void Principal::checarRobosAtivos()
{
    robo_acessado = vetorRobos->percorreLista();

    while(robo_acessado != NULL)
    {
        robo_acessado = vetorRobos->percorreLista();
    }
}

void Principal::transmitir()
{
    unsigned char *auxPacket;
    robo_acessado = vetorRobos->percorreLista();
    while(robo_acessado != NULL)
    {
        auxPacket = packet->montarPacoteRS232(robo_acessado->getNome(),robo_acessado->getMAC(), robo_acessado->getVelX(), robo_acessado->getVelY(),robo_acessado->getVelAng(), 0);
        radio->send(auxPacket);

        usleep(50); //melhor tempo custo beneficio encontrado para sicronizacao de dados transmissor-receptor
        robo_acessado = vetorRobos->percorreLista();
    }
}

void Principal::carregarRobos()
{
    while(arquivo->getNextLine() != 0)
    {
        vetorRobos->adicionarRobo(arquivo->getNumero(), arquivo->getMAC());
    }
}
Principal::~Principal() {}
