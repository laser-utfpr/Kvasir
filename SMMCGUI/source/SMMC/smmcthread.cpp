#include "smmcthread.hpp"

using namespace boost::interprocess;

SMMCThread::SMMCThread(SharedParameters &sp) : shared_parameters(sp)
{
    run_thread = true;

    generateKeys();

    shared_memory_object::remove(SHARED_MEMORY_BLOCK_NAME);
    shared_memory = new managed_shared_memory(create_only,
            SHARED_MEMORY_BLOCK_NAME, SHARED_MEMORY_SIZE);

    constructVisionSMVariables();
    constructAISMVariables();
    constructCommSMVariables();
}

void SMMCThread::generateKeys(void)
{
    do{ vision_write_key = randomAlphaNumericString(KEY_SIZE); }
        while(vision_write_key == EMPTY_KEY);
    do{ ai_write_key = randomAlphaNumericString(KEY_SIZE); }
        while(vision_write_key == EMPTY_KEY);
    do{ comm_write_key = randomAlphaNumericString(KEY_SIZE); }
        while(vision_write_key == EMPTY_KEY);
    do{ vision_read_key = randomAlphaNumericString(KEY_SIZE); }
        while(vision_write_key == EMPTY_KEY);
    do{ ai_read_key = randomAlphaNumericString(KEY_SIZE); }
        while(vision_write_key == EMPTY_KEY);
    do{ comm_read_key = randomAlphaNumericString(KEY_SIZE); }
        while(vision_write_key == EMPTY_KEY);
}

void SMMCThread::constructVisionSMVariables(void)
{
    sm_vision_write_key = shared_memory->construct<std::string>
                              (VISION_WRITE_KEY_MEMORY_NAME)();
    *sm_vision_write_key = EMPTY_KEY;

    sm_vision_read_key = shared_memory->construct<std::string>
                               (VISION_READ_KEY_MEMORY_NAME)();
    *sm_vision_read_key = EMPTY_KEY;

    sm_vision_field = shared_memory->construct<VisionField>
                              (VISION_FIELD_MEMORY_NAME)();
}

void SMMCThread::constructAISMVariables(void)
{
    sm_ai_write_key = shared_memory->construct<std::string>
                              (AI_WRITE_KEY_MEMORY_NAME)();
    *sm_ai_write_key = EMPTY_KEY;

    sm_ai_read_key = shared_memory->construct<std::string>
                               (AI_READ_KEY_MEMORY_NAME)();
    *sm_ai_read_key = EMPTY_KEY;
}

void SMMCThread::constructCommSMVariables(void)
{
    sm_comm_write_key = shared_memory->construct<std::string>
                              (COMM_WRITE_KEY_MEMORY_NAME)();
    *sm_comm_write_key = EMPTY_KEY;

    sm_comm_read_key = shared_memory->construct<std::string>
                               (COMM_READ_KEY_MEMORY_NAME)();
    *sm_comm_read_key = EMPTY_KEY;
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

void SMMCThread::stopThread(void)
{
    run_thread = false;
}

void SMMCThread::startVision(std::string path)
{
    std::string command;
    command += path;
    command += ' ';
    command += vision_write_key;
    command += ' ';
    command += vision_read_key;
    command += " &";
    int ignored_value = system(command.c_str());
}

void SMMCThread::startAI(std::string path)
{
    std::string command;
    command += path;
    command += ' ';
    command += ai_write_key;
    command += ' ';
    command += ai_read_key;
    command += " &";
    int ignored_value = system(command.c_str());
}

void SMMCThread::startComm(std::string path)
{
    std::string command;
    command += path;
    command += ' ';
    command += comm_write_key;
    command += ' ';
    command += comm_read_key;
    command += " &";
    int ignored_value = system(command.c_str());
}

void SMMCThread::updateVisionOutputSettings(void)
{
    //lock shared parameters
    *sm_vision_read_key = vision_read_key;
    //output variables to shared memory
    //unlock shared parameters
}

void SMMCThread::updateAIOutputSettings(void)
{
    //lock shared parameters
    *sm_ai_read_key = ai_read_key;
    //output variables to shared memory
    //unlock shared parameters
}

void SMMCThread::updateCommOutputSettings(void)
{
    //lock shared parameters
    *sm_comm_read_key = comm_read_key;
    //output variables to shared memory
    //unlock shared parameters
}

void SMMCThread::run()
{
    while(run_thread)
    {
        if(*sm_vision_write_key == vision_write_key)
        {
            //lock shared parameters
            //read variables
            //unlock shared parameters
            //emit signal
            *sm_vision_write_key = EMPTY_KEY;
        }
        if(*sm_ai_write_key == ai_write_key)
        {
            //lock shared parameters
            //read variables
            //unlock shared parameters
            //emit signal
            *sm_ai_write_key = EMPTY_KEY;
        }
        if(*sm_comm_write_key == comm_write_key)
        {
            //lock shared parameters
            //read variables
            //unlock shared parameters
            //emit signal
            *sm_comm_write_key = EMPTY_KEY;
        }
    }
}

#include "moc_smmcthread.cpp"
