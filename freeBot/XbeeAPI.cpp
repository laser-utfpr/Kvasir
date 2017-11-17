#include "XbeeAPI.h"
//--OK:
 char* XbeeAPI::montarPacote(char stringEndereco[],char msgByte1,char msgByte2, char msgByte3, char msgByte4, char msgByte5, char msgByte6){
  int i, j, endereco[8], aux;
  char* stringSaida= new char[31];
   char string_velX[4];
  char string_velY[4];
  char string_velAng[4];
   *((float*)&string_velX) = msgByte1;
  *((float*)&string_velY) = msgByte2;
  *((float*)&string_velAng) = msgByte3;

  //--Converter string ascii para hexa
  j=0;
  for(i=0;i<16;i++){
  //--para numeros: em ascii de 48 at� 57
    if(stringEndereco[i]>=48 && stringEndereco[i]<=57){
      aux = stringEndereco[i]-48;
      }
    //--para letras: em ascii de
    if(stringEndereco[i]>=97 && stringEndereco[i]<=102){
      aux = stringEndereco[i]-97+10;
      }
    //--para numeros pares, ele "empurra e grava"
    //--para numeros impares ele faz "ou" e grava
    if(i%2==0){
      endereco[j]=aux<<4;
      }
    else{
      endereco[j]=endereco[j] | aux;
      j++;
      }
    }
    //--Fim do conversor

  stringSaida[0] = 0x7E;  //--Encabezado
  stringSaida[1] = 0x00;  //--"Sempre" 0
  stringSaida[2] = 'T';//AMANHOENVIO;  //--Tama�o en Bytes del paquete (11)
  stringSaida[3] = 0x10;  //--Identificaci�n del comando de la API (0x01 para enviar a direcci�n de 16 bits)
  stringSaida[4] = 0x01;  //--Identificaci�n del paquete (cualquier numero entre 0x01 y 0xFF)
  stringSaida[5] = endereco[0];  //--Byte m�s significativo direcci�n destino
  stringSaida[6] = endereco[1];  //--Endereco do Destino
  stringSaida[7] = endereco[2];  //--Endereco do Destino
  stringSaida[8] = endereco[3];  //--Endereco do Destino
  stringSaida[9] = endereco[4];  //--Endereco do Destino
  stringSaida[10] = endereco[5]; //--Endereco do Destino
  stringSaida[11] = endereco[6]; //--Endereco do Destino
  stringSaida[12] = endereco[7]; //--Byte menos significativo direcci�n destino
  stringSaida[13] = 0xFF; //--Byte mais significativo 16-bit //--N�o meche
  stringSaida[14] = 0xFE; //--Byte menos Significativo 16-bit //--N�o meche
  stringSaida[15] = 0x00; //--Opciones, "0" utiliza opciones por defecto.
  stringSaida[16] = 0xa0; //--"Sempre" 0 - Esta opc�o regula um monte de coisa que n�o sei para que serve
  //stringSaida[17] = msgByte1; //--'X' - 1� Byte: velocidade em x
  //stringSaida[18] = msgByte2; //--'X' - 3� Byte: velocidade em y
  //stringSaida[19] = msgByte3; //--'X' - 5� Byte: velocidade Angular
  //stringSaida[20] = msgByte4; //--'X' - 4� Byte: chute/Status
   for(i=0; i<4; i++)
  {
    stringSaida[17+i]=string_velX[i];
    stringSaida[21+i]=string_velY[i];
    stringSaida[25+i]=string_velAng[i];
  }
  //stringSaida[17] = 0xa0;
  //stringSaida[18] = msgByte1;
  //stringSaida[19] = msgByte2;
  //stringSaida[20] = msgByte3;
  //stringSaida[21] = msgByte4;
  //stringSaida[22] = msgByte5;
  //stringSaida[23] = msgByte6;
  //--Calcular CheckSum
  aux=0;
  for(i=3;i<29;i++){
    aux=aux+stringSaida[i];
  }
  aux=0xff-(aux&0xff);

  stringSaida[29] = aux; //--Suma de verificaci�n
  stringSaida[30] = '\0';

return stringSaida;
  }
//
//int XbeeAPI::_desmontarStatus(char stringInformacao[]){
//int status;
//    switch(stringInformacao[3]){
//        case '00': //--sucesso
//         status=0;//--Sucesso
//        break;
//        case '24': //--fracasso: falta de sinal
//         status=1;
//        break;
//        default:
//         status=2;//--Erro desconhecido
//        break;
//    }
//return status;
//}

//--OK:
void XbeeAPI::_desmontarComando(char stringInformacao[]){
   // _byte1 = stringInformacao[15];
   // _byte2 = stringInformacao[16];
   // _byte3 = stringInformacao[17];
   // _byte4 = stringInformacao[18];
   _byte1 = stringInformacao[18];
   _byte2 = stringInformacao[19];
   _byte3 = stringInformacao[20];
   _byte4 = stringInformacao[21];
   _byte5 = stringInformacao[22];
   _byte6 = stringInformacao[23];
   //_byte4 = stringInformacao[20];
}


int XbeeAPI::desmontarPacote(char stringInformacao[]){//--Fun�ao que encaminha comando e
    char saida;                                                //--retorna o erro +1 do zigBee
    if(stringInformacao[2]==0x1a){
        _desmontarComando(stringInformacao);
        saida = 0;//--Deu boa
    }
    else {//if (stringInformacao[3]==0x8b){
        //_desmontarStatus(stringInformacao);
        saida = stringInformacao[8] + 1;//--Pega o c�digo do erro (+1), gambiarra
    }
    return saida;
}

//--OK:
char XbeeAPI::getByte1(){
    return _byte1;
    
}
//--OK:
char XbeeAPI::getByte2(){
    return _byte2;
}
//--OK:
char XbeeAPI::getByte3(){
    return _byte3;
}
//--OK:
char XbeeAPI::getByte4(){
    return _byte4;
}
