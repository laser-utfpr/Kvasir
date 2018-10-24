#include "Buffer.h"

Buffer::Buffer(unsigned char _byte)
{
    amount = 1;
    Byte = _byte;
    next = NULL;
}

Buffer* Buffer::addByte(unsigned char _byte, Buffer* head)
{

    if(head == NULL)
    {
        head = new Buffer(_byte);
    }
    else
    {
        Buffer* cur = head;
        while(cur->next!=NULL)
        {
            cur = cur->next;
        }
        cur->next = new Buffer(_byte);
        head->amount++;
    }

    return head;
}

Buffer* Buffer::removeByte(Buffer* head)
{

    if(head != NULL)
    {
        Buffer* cur = head;
        cur->amount--;
        head = head->next;
        if(head != NULL)
        {
            head->amount = cur->amount;
        }
        delete cur;
    }
    return head;
}

int Buffer::getSize()
{
    return amount;
}

unsigned char Buffer::getByte()
{
    return Byte;
}
