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

    if(RS232_OpenComport(CPORT_NR, BDRATE, "8N1"))
    {
        printf("AVISO: NENHUMA serial encontrada!!\n");
    }
    RS232_enableDTR(CPORT_NR);
    RS232_enableRTS(CPORT_NR);

}

void Radio::send(unsigned char *transmitir)
{

    stringstream buffer;
    string sendVariable;
    RS232_SendBuf(CPORT_NR, (unsigned char*) transmitir, TAMANHODOPACOTE);
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

