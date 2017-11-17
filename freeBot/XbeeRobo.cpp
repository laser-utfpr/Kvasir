#include "XbeeRobo.h"
#include "Arduino.h"

XbeeRobo::XbeeRobo(){
  //vetorTransmitir = new char[23];
  _velocidadeY = 0;
  _velocidadeX = 0;
}
XbeeRobo::~XbeeRobo(){
  delete vetorTransmitir;
  }

void XbeeRobo::receberRS232(){
  unsigned char key;
  int i;
  char byte_entrada[12]; //Converte 12 chars em 3 floats
  int pwm;
  float vel;

  while(Serial.available() > 0){
    key=Serial.read();
    if(key==0xa0){
        for(i=0; i<12; i++)
        {
          //delay(10);
          byte_entrada[i]=Serial.read();
          delay(10);
        }
        /*delay(10);
        byte1 = Serial.read();
        delay(10);
        byte2 = Serial.read();
        delay(10);
        byte3 = Serial.read();        
        delay(10);
        byte4 = Serial.read();
        delay(10);
        byte5 = Serial.read();
        delay(10);
        byte6 = Serial.read();        
        delay(10);*/

        if(key == 0xa0 ){//&& byte3 == 0xa1){
          Serial.println("vou  cetar a velocidade");
          //_velocidadeX = _converteVelocidade(byte1, byte2);
            _velocidadeX = *(float*)&byte_entrada[0];//
          //_velocidadeY = _converteVelocidade(byte3, byte4);
            _velocidadeY = *(float*)&byte_entrada[4];
            _velAng = *(float*)&byte_entrada[8];
          //pwm = (int)(vel *180/.6)+90;//(0->255)(valor com pwm não linear)
          //pwm = (int)((vel+.3)*50/.6)+65;//--valor dentro do linear          
          } 
//        else if(key == 0xa0 && byte3 == 0xa2){
//          _velocidadeX = ((((float)byte1*0.6)/252)-.3);
//          _velocidadeY = ((((float)byte2*0.6)/252)-.3);
//          
//          //--pwm = (int)(vel *180/.6)+90;//--(0->255)
//         // pwm = (int)((vel+.3)*50/.6)+65;
//          }    
      }//--Fim IF key
    }//--Fim do While
  
 /* byte tecla;
  int a;//---  vmos usar 255 para Dizer sobre o primeiro pacote:
 while(Serial.available() != 0)
    if(tecla == 0xA0)
  {
      tecla = Serial.read();
      if(tecla == 0xA1){
        tecla = Serial.read();
        if(tecla == 0xA2){
          tecla = Serial.read();
          }
        if(tecla == 0xA3){
          _velocidadeX = .3;
          _velocidadeY = .3;
                    
          }
         else if(tecla == 0x00){
          _velocidadeX = -.3;
          _velocidadeY = -.3;
          }
        }
  }
 */ 
/*    if(Serial.available()>0){
       if(Serial.read()==255){
          if(Serial.available()>0){
             _velocidadeX = (((float)Serial.read())*0.3)/(126);
             _velocidadeY = (((float)Serial.read())*0.3)/(126);
             a = Serial.read(); //--Le duas vezes só de alegria 
             //a = Serial.read(); //--Le duas vezes só de alegria
             delay(10);//--espera as duas coisas chegar
             _pronto =1; 
          }
        }_pronto =1; 
      }
*/
}


void XbeeRobo::enviarComando(char enderecoIN[]){
     //--unsigned char *vetorTransmitir;//--Movida pra construtora
     char velPkg1, velPkg2, aux3='a', aux4='a', aux5='a', aux6='a';
     //--vetorTransmitir = new unsigned char[23];//--Movida pra construtora
     //--O robo envia ao pc 4 bytes, sendo, os dois primeiros as 4 velocidades e o 3 sobre o status no geral. O quarto byte envia 'a', só por enviar.
     velPkg1=_velEnviar1<<4;
     velPkg1=velPkg1 || _velEnviar2;

     velPkg2=_velEnviar3<<4;
     velPkg2=velPkg2 || _velEnviar4;

     vetorTransmitir = _xbee.montarPacote(enderecoIN,velPkg1,velPkg2,aux3,aux4, aux5, aux6);
  }

void XbeeRobo::atualizarBuffer(){
  char vetorString[31];
  int i;
  //char aux[4];

  while(Serial.available()>0){
    vetorString[0]=Serial.read();
    if(vetorString[0] == 0x7e){
          for(i=1;i<4;i++){
            vetorString[i]=Serial.read();//--lê de 1 até 3
          }//--Fim FOR
          if(vetorString[2]==0x1a){//0x1f){ //0x90){//--Valor para tipo de PACOTE RECEBIDO!!
             Serial.println("vou ler tudo");
             for(i=4;i<31;i++){
                vetorString[i]=Serial.read();
                }//--Fim FOR
             _status=_xbee.desmontarPacote(vetorString);
            // if (_status == 0){
              //  _velocidadeX = _converteVelocidade(_xbee.getByte1(), _xbee.getByte2());
              //  _velocidadeY = _converteVelocidade(_xbee.getByte3(), _xbee.getByte4());
              //   for(i=0; i<4; i++)
               //  {
               //   aux[i]=vetorString[20-i];
               //  }
                 _velocidadeX = *(float*)&vetorString[17];
                 //_velocidadeX = *(float*)&aux[0];
                // for(i=0; i<4; i++)
                // {
                //  aux[i]=vetorString[24-i];
                // }
                 _velocidadeY = *(float*)&vetorString[21];
                 //_velocidadeY = *(float*)&aux[0];
               // _velocidadeX = (float)_xbee.getByte1();
               // _velocidadeY = (float)_xbee.getByte2();
               _velAng = *(float*)&vetorString[25];
               _pronto =1;  
           //}
          }//--Fim IF 0x90
     }//--Fim inicio do pacote
  }//--Fim do while
}//--Fim método  


float XbeeRobo::_converteVelocidade(char dadoIN1, char dadoIN2){
  float x;
  int lsb = dadoIN1;
  int msb = dadoIN2<<8;
  x=*(float*)(lsb|msb);
       // x=(dadoIN*(.4))/244;
     //  x=(((dadoIN*0.6)/252)-.3);
  return x;
}

int XbeeRobo::pronto(){
int a;
a=_pronto;
_pronto = 0;
return a;
}

float XbeeRobo::getVelY(){
    return _velocidadeY;
  }
  
float XbeeRobo::getVelX(){
    return _velocidadeX;
}
float XbeeRobo::getVelAng(){
  return _velAng;
}



