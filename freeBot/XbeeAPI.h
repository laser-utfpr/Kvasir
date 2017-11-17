#define TAMANHODOPACOTE 31
#define TAMANHOENVIO 0x1f

#define TAMANHODOPACOTERX 31
#define TAMANHORECEBIDO 0x1f

#ifndef _XBEEAPI_H_
#define _XBEEAPI_H_

class XbeeAPI{
  private:
      //char *_desmontarSucesso(char stringInformacao[]);
      //char *_desmontarFalha(char stringInformacao[]);
      void _desmontarComando(char stringInformacao[]);
      int _desmontarStatus(char stringInformacao[]);
      char _byte1;
      char _byte2;
      char _byte3;
      char _byte4;
      char _byte5;
      char _byte6;

  public:
      XbeeAPI(){};
      ~XbeeAPI(){};

      char getByte1();
      char getByte2();
      char getByte3();
      char getByte4();
      char getByte5();
      char getByte6();

      char *montarPacote(char stringEndereco[],char msgByte1,char msgByte2,char msgByte3,char msgByte4, char msgByte5, char msgByte6);
      int desmontarPacote(char stringInformacao[]);
};
#endif
