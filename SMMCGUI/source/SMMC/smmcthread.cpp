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
    do{ vision_shutdown_key = randomAlphaNumericString(KEY_SIZE); }
        while(vision_shutdown_key == EMPTY_KEY);
    do{ ai_shutdown_key = randomAlphaNumericString(KEY_SIZE); }
        while(vision_shutdown_key == EMPTY_KEY);
    do{ comm_shutdown_key = randomAlphaNumericString(KEY_SIZE); }
        while(vision_shutdown_key == EMPTY_KEY);
}

void SMMCThread::constructVisionSMVariables(void)
{
    sm_vision_write_key = shared_memory->construct<std::string>
                              (VISION_WRITE_KEY_MEMORY_NAME)();
    *sm_vision_write_key = EMPTY_KEY;

    sm_vision_read_key = shared_memory->construct<std::string>
                               (VISION_READ_KEY_MEMORY_NAME)();
    *sm_vision_read_key = EMPTY_KEY;

    sm_vision_shutdown_key = shared_memory->construct<std::string>
                               (VISION_SHUTDOWN_KEY_MEMORY_NAME)();
    *sm_vision_shutdown_key = EMPTY_KEY;

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

    sm_ai_shutdown_key = shared_memory->construct<std::string>
                               (AI_SHUTDOWN_KEY_MEMORY_NAME)();
    *sm_ai_shutdown_key = EMPTY_KEY;

    sm_ai_field = shared_memory->construct<AIField>
                              (AI_FIELD_MEMORY_NAME)();
}

void SMMCThread::constructCommSMVariables(void)
{
    sm_comm_write_key = shared_memory->construct<std::string>
                              (COMM_WRITE_KEY_MEMORY_NAME)();
    *sm_comm_write_key = EMPTY_KEY;

    sm_comm_read_key = shared_memory->construct<std::string>
                               (COMM_READ_KEY_MEMORY_NAME)();
    *sm_comm_read_key = EMPTY_KEY;

    sm_comm_shutdown_key = shared_memory->construct<std::string>
                               (COMM_SHUTDOWN_KEY_MEMORY_NAME)();
    *sm_comm_shutdown_key = EMPTY_KEY;

    sm_robot_movement = shared_memory->construct<Movement>
                              (ROBOT_MOVEMENT_MEMORY_NAME)[N_ROBOTS]();
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

void SMMCThread::startVision(void)
{
    *sm_vision_shutdown_key = EMPTY_KEY;
    std::string path = shared_parameters.getVisionPath();
    std::string command;
    command += path;
    command += ' ';
    command += vision_write_key;
    command += ' ';
    command += vision_read_key;
    command += ' ';
    command += vision_shutdown_key;
    command += " &";
    int ignored_value = system(command.c_str());
}

void SMMCThread::startAI(void)
{
    *sm_ai_shutdown_key = EMPTY_KEY;
    std::string path = shared_parameters.getAIPath();
    std::string command;
    command += path;
    command += ' ';
    command += ai_write_key;
    command += ' ';
    command += ai_read_key;
    command += ' ';
    command += ai_shutdown_key;
    command += " &";
    int ignored_value = system(command.c_str());
}

void SMMCThread::startComm(void)
{
    *sm_comm_shutdown_key = EMPTY_KEY;
    std::string path = shared_parameters.getCommPath();
    std::string command;
    command += path;
    command += ' ';
    command += comm_write_key;
    command += ' ';
    command += comm_read_key;
    command += ' ';
    command += comm_shutdown_key;
    command += " &";
    int ignored_value = system(command.c_str());
}

void SMMCThread::shutdownVision(void)
{
    *sm_vision_shutdown_key = vision_shutdown_key;
}

void SMMCThread::shutdownAI(void)
{
    *sm_ai_shutdown_key = ai_shutdown_key;
}

void SMMCThread::shutdownComm(void)
{
    *sm_comm_shutdown_key = comm_shutdown_key;
}

void SMMCThread::updateVisionOutputSettings(void)
{
    *sm_vision_read_key = vision_read_key;
    //output settings to shared memory
}

void SMMCThread::updateAIOutputSettings(void)
{
    *sm_ai_read_key = ai_read_key;
    //output settings to shared memory
}

void SMMCThread::updateCommOutputSettings(void)
{
    *sm_comm_read_key = comm_read_key;
    //no comm settings to be output for now
}

void SMMCThread::run()
{
    while(run_thread)
    {
        //receiving variables
        if(*sm_vision_write_key == vision_write_key)
        {
            shared_parameters.readVisionParameters(*sm_vision_field);
            emit visionInputUpdate();
            *sm_vision_write_key = EMPTY_KEY;
        }
        if(*sm_ai_write_key == ai_write_key)
        {
            shared_parameters.readAIParameters(*sm_ai_field);
            emit aiInputUpdate();
            *sm_ai_write_key = EMPTY_KEY;
        }
        if(*sm_comm_write_key == comm_write_key)
        {
            //no comm parameters to be recieved for now
            emit commInputUpdate();
            *sm_comm_write_key = EMPTY_KEY;
        }

        //auto sending variables from Vision to AI
        AIField sp_ai_field = shared_parameters.getAIField();
        sm_ai_field->image_width = sp_ai_field.image_width;
        sm_ai_field->image_height = sp_ai_field.image_height;
        sm_ai_field->ball = sp_ai_field.ball;
        for(int i=0; i<N_ROBOTS; i++)
            sm_ai_field->robot[i] = *(static_cast<Entity*>(&(sp_ai_field.robot[i])));
        for(int i=0; i<N_ROBOTS; i++)
            sm_ai_field->enemy_robot[i] = sp_ai_field.enemy_robot[i];
        *sm_ai_read_key = ai_read_key;

        //auto sending variables from AI to Communication
        for(int i=0; i<N_ROBOTS; i++)
            sm_robot_movement[i] = shared_parameters.getRobotMovement(i);
        *sm_comm_read_key = comm_read_key;

    }
}

#include "moc_smmcthread.cpp"
