#include "MemoryClient.h"

MemoryClient::MemoryClient(char nameIN[20]){
    strcpy(_nameProcess, nameIN);
    //_setup();
}
MemoryClient::MemoryClient(){
//  _nameProcess = 'Unnamed Process'
strcpy(_nameProcess, "Unnamed Process");
  //_setup();
}
void MemoryClient::_setup(int nameIN){
      _key = CONSTANTE_DA_CHAVE + nameIN; //--nome do segmento
     // while(1);
      _shmsize = sizeof(struct RobotMsg); //--define o tamanho do segmento (16 Robôs no máximo!!)
  //--Procurando o segmento
      while ((_shmid = shmget(_key, _shmsize, IPC_CREAT | 0666)) < 0) {//--substitui o valor constante!!
        printf("Setor de memória compátivel não encontrado!\nContinuando Busca...\n");
          //return;
      }
  //--Now we attach the segment to our data space.
      if ((_pacote      = (struct RobotMsg*)shmat(_shmid, NULL, 0)) == ((struct RobotMsg*) -1)) {
          printf("Erro ao acoplar as variaveis locais às compartilhadas");
          return;
      }
      //while(1);
}
void MemoryClient::_unSetup(){
if (shmdt(_pacote)== -1){
          perror("acoplamento impossivel") ;
     }
}


void MemoryClient::sendVelX(int nameOfRobotIN, float velXIN){
//  _pacote[nameOfRobotIN].process = _nameProcess;
_setup(nameOfRobotIN);
 strcpy(_pacote->process, _nameProcess);
  _pacote->velX = velXIN;
_unSetup();
}
void MemoryClient::sendVelY(int nameOfRobotIN, float velYIN){
//  _pacote[nameOfRobotIN].process = _nameProcess;
_setup(nameOfRobotIN);
  strcpy(_pacote->process, _nameProcess);
  _pacote->velY = velYIN;
_unSetup();
}
void MemoryClient::sendChute(int nameOfRobotIN, int chuteIN){
//  _pacote[nameOfRobotIN].process = _nameProcess;
_setup(nameOfRobotIN);
  strcpy(_pacote->process, _nameProcess);
  _pacote->chute = chuteIN;
_unSetup();
}
void MemoryClient::sendStatus(int nameOfRobotIN, int statusIN){
//  _pacote[nameOfRobotIN].process = _nameProcess;
_setup(nameOfRobotIN);
  strcpy(_pacote->process, _nameProcess);
  _pacote->status = statusIN;
_unSetup();
}

int MemoryClient::getID(){
    return _key;
}
void MemoryClient::setNameOfProcess(char nameIN[20]){
  strcpy(_nameProcess, nameIN);
}
