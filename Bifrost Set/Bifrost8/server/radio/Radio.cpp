/**************************************************

**************************************************/
#include "Radio.h"

using namespace std;
using std::stringstream;

Radio::Radio()
{
    Radio::setup();
}

void Radio::setup()
{
    if(RS232_OpenComport(CPORT_NR, BDRATE))
    {
        printf("AVISO: NENHUMA serial encontrada!!\n");
    }
}

void Radio::send(unsigned char *transmitir)
{

    stringstream buffer;
    string sendVariable;
    RS232_SendBuf(CPORT_NR, (unsigned char*) transmitir, TAMANHODOPACOTE);//mudar para tamanho envio
}

/*char* Radio::receive(){
  char saida[3];
  unsigned char buf[2];
  int n;

    n = RS232_PollComport(_cport_nr, buf, 2);

    if(n > 0)
    {
      saida[0] = buf[0];
      saida[1] = buf[1];
      saida[2] = '\0';
    }
    usleep(100000);  // sleep for 100 milliSeconds
  return saida;
}*/

