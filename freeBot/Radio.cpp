#include "Radio.hpp"

#ifndef XBEE
Radio::Radio() : RF24(CE_PIN, CSN_PIN)
{
    radioSets();
}
void Radio::radioSets()
{
    begin();
    setRetries(DELAY_TRANS, RETRIES);
    setChannel(uint8_t(CHANNEL+2*NAME));
    setAddressWidth(W_ADDRESS);
    setPayloadSize(W_DATA);
    setDataRate(DATA_RATE);
}
#endif
