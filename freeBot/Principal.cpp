#include "Principal.hpp"

Principal::Principal()
{
    rf_receiver = new RFreceiver();
    robot = new Robot();
}

void Principal::start()
{
    while(1)
    {
        rf_receiver->receiveData();
        do
        {
            robot->move(rf_receiver->getVelX(), rf_receiver->getVelY(), rf_receiver->getVelAng());
        }while(rf_receiver->updateBuffer());
        delay(COMMUNICATION_DELAY);
     }
}
