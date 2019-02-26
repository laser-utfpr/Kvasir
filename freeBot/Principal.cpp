#include "Principal.hpp"

Principal::Principal()
{
    rf_receiver = new RFreceiver();
    robot = new Robot();
}

void Principal::start()
{
    long time = millis();
    while(1)
    {
        rf_receiver->receiveData();
        if(rf_receiver->updateBuffer())
        {
            robot->move(rf_receiver->getVelX(), rf_receiver->getVelY(), rf_receiver->getVelAng()); 
        }
        //do
        //{
        //    robot->move(rf_receiver->getVelX(), rf_receiver->getVelY(), rf_receiver->getVelAng());
            
        //}while(rf_receiver->updateBuffer());
        //delay(COMMUNICATION_DELAY);
        if(millis()-time >=1000)
        {
            time = millis();
            Serial.println("1 segundo");
        }
    }
    
}
