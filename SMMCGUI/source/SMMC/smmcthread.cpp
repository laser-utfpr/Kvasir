#include "smmcthread.hpp"

SMMCThread::SMMCThread(SharedParameters &sp) : shared_parameters(sp)
{

}

SMMCThread::~SMMCThread()
{

}

void SMMCThread::run()
{
    std::cout << "smmc thread running!" << std::endl;
}

#include "moc_smmcthread.cpp"
