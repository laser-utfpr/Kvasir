#include "smmcthread.hpp"

using namespace boost::interprocess;

SMMCThread::SMMCThread(SharedParameters &sp) : shared_parameters(sp)
{
    generateKeys();

    shared_memory_object::remove(SHARED_MEMORY_BLOCK_NAME);
    shared_memory = new managed_shared_memory(create_only,
            SHARED_MEMORY_BLOCK_NAME, SHARED_MEMORY_SIZE);

    constructVisionSMVariables();
    constructAISMVariables();
    constructCommunicationSMVariables();
}

void SMMCThread::generateKeys(void)
{
    do{ vision_write_key = randomAlphaNumericString(KEY_SIZE); }
        while(vision_write_key == EMPTY_KEY);
    do{ ai_write_key = randomAlphaNumericString(KEY_SIZE); }
        while(vision_write_key == EMPTY_KEY);
    do{ communication_write_key = randomAlphaNumericString(KEY_SIZE); }
        while(vision_write_key == EMPTY_KEY);
    do{ vision_read_key = randomAlphaNumericString(KEY_SIZE); }
        while(vision_write_key == EMPTY_KEY);
    do{ ai_read_key = randomAlphaNumericString(KEY_SIZE); }
        while(vision_write_key == EMPTY_KEY);
    do{ communication_read_key = randomAlphaNumericString(KEY_SIZE); }
        while(vision_write_key == EMPTY_KEY);
}

void SMMCThread::constructVisionSMVariables(void)
{
    sm_vision_write_key = shared_memory->construct<std::string>
                              (VISION_WRITE_KEY_MEMORY_NAME)();
    sm_vision_read_key = shared_memory->construct<std::string>
                               (VISION_READ_KEY_MEMORY_NAME)();
    sm_vision_field = shared_memory->construct<VisionField>
                              (VISION_FIELD_MEMORY_NAME)();
}

void SMMCThread::constructAISMVariables(void)
{

}

void SMMCThread::constructCommunicationSMVariables(void)
{

}

SMMCThread::~SMMCThread()
{
    shared_memory_object::remove(SHARED_MEMORY_BLOCK_NAME);
    delete shared_memory;
}

std::vector<char> SMMCThread::alphaNumericArray(void)
{
    return std::vector<char>(
    {'0','1','2','3','4',
     '5','6','7','8','9',
     'A','B','C','D','E','F',
     'G','H','I','J','K',
     'L','M','N','O','P',
     'Q','R','S','T','U',
     'V','W','X','Y','Z',
     'a','b','c','d','e','f',
     'g','h','i','j','k',
     'l','m','n','o','p',
     'q','r','s','t','u',
     'v','w','x','y','z'
    });
}

std::string SMMCThread::randomAlphaNumericString(int size)
{
    std::string str;
    str.resize(size);

    std::vector<char> alpha_num = alphaNumericArray();

    std::random_device seeder{};
    std::mt19937 twister{seeder()};
    std::uniform_int_distribution<> dis(0, alpha_num.size() - 1);

    for(int i=0; i<size; i++)
        str[i] = alpha_num[dis(twister)];

    return str;
}

void SMMCThread::run()
{
    while(1)
    {
        ;
    }
}

#include "moc_smmcthread.cpp"
