//biblioteca criada para manutencao de um Buffer local. Nada mais eh que uma fila de bytes, com funcoes basicas da mesma

#ifndef _BUFFER_H_
#define _BUFFER_H_

#include <stdlib.h>

class Buffer{
    int amount;
    unsigned char byte;

public:
    Buffer* next;
    Buffer(unsigned char _byte);
    Buffer* addByte(unsigned char _byte, Buffer* head);
    Buffer* removeByte(Buffer* head);
    int getSize();
    unsigned char getByte();
    ~Buffer(){};
};

#endif
