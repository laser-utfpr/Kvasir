#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_

#include "MemoryClient.h"
#include "MousePointer.h"
#include <stdio.h>
#define VEL_MAX 0.3
class Principal{
private:
    MousePointer _mouse;
    MemoryClient* _client;
    void _transmitir();
public:
    Principal();
    ~Principal(){};
};
#endif

Principal::Principal(){
        _client = new MemoryClient();
        _transmitir();
        delete _client;
}

void Principal::_transmitir(){
    int robo=100;
    int x,y;
    float velX,velY;

    do{
        printf ("Qual robô será controlado?\n");
        scanf("%d",&robo);
        printf ("Robô %d escolhido.\n", robo);
    }while(robo > 16);

    _mouse._calibrar();
    while(1){
        x = _mouse.getEixoX();
        y = _mouse.getEixoY();
        //--Cria uma janela de detecção
        if (x>=300)
            x=300;
        if (x<=-300)
            x=-300;
        if (y>=300)
            y=300;
        if (y<=-300)
            y=-300;
        if (x>-50&&x<50)
            x=0;
        if (y>-50&&y<50)
            y=0;
        //--regra de 3:
        velX = (x * VEL_MAX)/300.0;
        velY = (y * VEL_MAX)/300.0;
        printf("Velocidades: %f,%f\n", velX, velY);
        _client->sendVelX(robo, velX);
        _client->sendVelY(robo, velY);
        _client->sendVelAng(robo, 0);
    }
}
