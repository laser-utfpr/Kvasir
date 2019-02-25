//biblioteca feita para os sets que garantem o funcionamento do nRF24L01

#ifndef _RADIOSETS_HPP_
#define _RADIOSETS_HPP_

#include <SPI.h>
#include "BotConstants.h"
#include <nRF24L01.h>
#include <RF24.h>

class Radio : public RF24{
    void radioSets();
public:
    Radio();
    ~Radio() {}

};

#endif
