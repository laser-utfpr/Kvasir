#include "smmcthread.hpp"

using namespace boost::interprocess;

SMMCThread::SMMCThread(SharedParameters &sp, QObject *mainwindow) : shared_parameters(sp)
{
    //this->moveToThread(this);

    std::cout << "SMMC thread created" << std::endl << std::endl;
    run_thread = true;

    connect(this, SIGNAL(sendVisionChangesToAI()), this, SLOT(updateAIFromVision()));
    connect(this, SIGNAL(sendAIChangeToComm()), this, SLOT(updateCommFromAI()));

    connect(this, SIGNAL(visionInputUpdate()), mainwindow, SLOT(handleVisionUpdate()));
    connect(this, SIGNAL(aiInputUpdate()), mainwindow, SLOT(handleAIUpdate()));
    connect(this, SIGNAL(commInputUpdate()), mainwindow, SLOT(handleCommUpdate()));

    generateKeys();
    std::cout << std::endl <<"Modules keys generated:" << std::endl;
    std::cout << "Vision write key: " << vision_write_key << std::endl;
    std::cout << "Vision read key: " << vision_read_key << std::endl;
    std::cout << "Vision shutdown key: " << vision_shutdown_key << std::endl;
    std::cout << "AI write key: " << ai_write_key << std::endl;
    std::cout << "AI read key: " << ai_read_key << std::endl;
    std::cout << "AI shutdown key: " << ai_shutdown_key << std::endl;
    std::cout << "Comm write key: " << comm_write_key << std::endl;
    std::cout << "Comm read key: " << comm_read_key << std::endl;
    std::cout << "Comm shutdown key: " << comm_shutdown_key << std::endl << std::endl;

    shared_memory_object::remove(SHARED_MEMORY_BLOCK_NAME);
    shared_memory = new managed_shared_memory(create_only,
            SHARED_MEMORY_BLOCK_NAME, SHARED_MEMORY_SIZE);

    char_allocator = new CharAllocator(shared_memory->get_segment_manager());
    string_allocator = new StringAllocator(shared_memory->get_segment_manager());
    color_allocator = new ColorAllocator(shared_memory->get_segment_manager());
    colored_object_allocator = new ColoredObjectAllocator(shared_memory->get_segment_manager());
    float_allocator = new FloatAllocator(shared_memory->get_segment_manager());

    constructVisionSMVariables();
    constructAISMVariables();
    constructCommSMVariables();
}

SMMCThread::~SMMCThread()
{
    delete char_allocator;
    delete string_allocator;
    delete color_allocator;
    delete colored_object_allocator;
    shared_memory_object::remove(SHARED_MEMORY_BLOCK_NAME);
    delete shared_memory;
}

void SMMCThread::generateKeys(void)
{
    //creates a new key for each one, if it unluckily is the EMPTY_KEY tries again
    do{ vision_write_key = randomAlphaNumericString(KEY_SIZE); }
        while(vision_write_key == EMPTY_KEY);
    do{ ai_write_key = randomAlphaNumericString(KEY_SIZE); }
        while(ai_write_key == EMPTY_KEY);
    do{ comm_write_key = randomAlphaNumericString(KEY_SIZE); }
        while(comm_write_key == EMPTY_KEY);
    do{ vision_read_key = randomAlphaNumericString(KEY_SIZE); }
        while(vision_read_key == EMPTY_KEY);
    do{ ai_read_key = randomAlphaNumericString(KEY_SIZE); }
        while(ai_read_key == EMPTY_KEY);
    do{ comm_read_key = randomAlphaNumericString(KEY_SIZE); }
        while(comm_read_key == EMPTY_KEY);
    do{ vision_shutdown_key = randomAlphaNumericString(KEY_SIZE); }
        while(vision_shutdown_key == EMPTY_KEY);
    do{ ai_shutdown_key = randomAlphaNumericString(KEY_SIZE); }
        while(ai_shutdown_key == EMPTY_KEY);
    do{ comm_shutdown_key = randomAlphaNumericString(KEY_SIZE); }
        while(comm_shutdown_key == EMPTY_KEY);
}

void SMMCThread::constructVisionSMVariables(void)
{
    //creates the variables' space on the shared memory
    sm_vision_write_key = shared_memory->construct<BoostInterprocessString>
                              (VISION_WRITE_KEY_MEMORY_NAME)(*char_allocator);
    *sm_vision_write_key = EMPTY_KEY;

    sm_vision_read_key = shared_memory->construct<BoostInterprocessString>
                               (VISION_READ_KEY_MEMORY_NAME)(*char_allocator);
    *sm_vision_read_key = EMPTY_KEY;

    sm_vision_shutdown_key = shared_memory->construct<BoostInterprocessString>
                               (VISION_SHUTDOWN_KEY_MEMORY_NAME)(*char_allocator);
    *sm_vision_shutdown_key = EMPTY_KEY;

    sm_vision_field = shared_memory->construct<VisionField>
                              (VISION_FIELD_MEMORY_NAME)(*color_allocator, *colored_object_allocator, *float_allocator);
}

void SMMCThread::constructAISMVariables(void)
{
    //creates the variables' space on the shared memory
    sm_ai_write_key = shared_memory->construct<BoostInterprocessString>
                              (AI_WRITE_KEY_MEMORY_NAME)(*char_allocator);
    *sm_ai_write_key = EMPTY_KEY;

    sm_ai_read_key = shared_memory->construct<BoostInterprocessString>
                               (AI_READ_KEY_MEMORY_NAME)(*char_allocator);
    *sm_ai_read_key = EMPTY_KEY;

    sm_ai_shutdown_key = shared_memory->construct<BoostInterprocessString>
                               (AI_SHUTDOWN_KEY_MEMORY_NAME)(*char_allocator);
    *sm_ai_shutdown_key = EMPTY_KEY;

    sm_ai_field = shared_memory->construct<AIField>
                              (AI_FIELD_MEMORY_NAME)(*char_allocator, *string_allocator);
}

void SMMCThread::constructCommSMVariables(void)
{
    //creates the variables' space on the shared memory
    sm_comm_write_key = shared_memory->construct<BoostInterprocessString>
                              (COMM_WRITE_KEY_MEMORY_NAME)(*char_allocator);
    *sm_comm_write_key = EMPTY_KEY;

    sm_comm_read_key = shared_memory->construct<BoostInterprocessString>
                               (COMM_READ_KEY_MEMORY_NAME)(*char_allocator);
    *sm_comm_read_key = EMPTY_KEY;

    sm_comm_shutdown_key = shared_memory->construct<BoostInterprocessString>
                               (COMM_SHUTDOWN_KEY_MEMORY_NAME)(*char_allocator);
    *sm_comm_shutdown_key = EMPTY_KEY;

    sm_robot_movement = shared_memory->construct<Movement>
                              (ROBOT_MOVEMENT_MEMORY_NAME)[N_ROBOTS]();
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
    //returns a (high quality!)random aplha numeric string
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
    //starts Vision passing it's keys
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
    //starts AI passing it's keys
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
    //starts Communication passing it's keys
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
    *sm_vision_shutdown_key = vision_shutdown_key.c_str();
    usleep(MODULE_SHUTDOWN_WAIT_TIME_US);
    *sm_vision_shutdown_key = EMPTY_KEY;
}

void SMMCThread::shutdownAI(void)
{
    *sm_ai_shutdown_key = ai_shutdown_key.c_str();
    usleep(MODULE_SHUTDOWN_WAIT_TIME_US);
    *sm_vision_shutdown_key = EMPTY_KEY;
}

void SMMCThread::shutdownComm(void)
{
    *sm_comm_shutdown_key = comm_shutdown_key.c_str();
    usleep(MODULE_SHUTDOWN_WAIT_TIME_US);
    *sm_vision_shutdown_key = EMPTY_KEY;
}

void SMMCThread::updateVisionOutputSettings(void)
{
    std::cout << std::endl << "Outputting Vision settings" << std::endl << std::endl;
    //outputting settings to shared memory
    sm_vision_field->ball_color = shared_parameters.getBallColor();
    sm_vision_field->ally_center = shared_parameters.getAllyCenter();
    sm_vision_field->enemy_center = shared_parameters.getEnemyCenter();
    auto tags = shared_parameters.getTags();
    sm_vision_field->ally_tag.insert(sm_vision_field->ally_tag.begin(), tags.begin(), tags.end());
    sm_vision_field->searched_region_ulc = shared_parameters.getSearchedRegionULC();
    sm_vision_field->searched_region_lrc = shared_parameters.getSearchedRegionLRC();

    //writing key
    *sm_vision_read_key = vision_read_key.c_str();
}

void SMMCThread::updateAIOutputSettings(void)
{
    std::cout << std::endl << "Outputting AI settings" << std::endl << std::endl;
    //outputting settings to shared memory
    sm_ai_field->playable_field_ulc = shared_parameters.getPlayableFieldULC();
    sm_ai_field->playable_field_lrc = shared_parameters.getPlayableFieldLRC();
    sm_ai_field->left_goal_ulc = shared_parameters.getLeftGoalULC();
    sm_ai_field->left_goal_lrc = shared_parameters.getLeftGoalLRC();
    sm_ai_field->right_goal_ulc = shared_parameters.getRightGoalULC();
    sm_ai_field->right_goal_lrc = shared_parameters.getRightGoalLRC();
    sm_ai_field->left_goalkeeper_area_ulc = shared_parameters.getLeftGKAreaULC();
    sm_ai_field->left_goalkeeper_area_lrc = shared_parameters.getLeftGKAreaLRC();
    sm_ai_field->right_goalkeeper_area_ulc = shared_parameters.getRightGKAreaULC();
    sm_ai_field->right_goalkeeper_area_lrc = shared_parameters.getRightGKAreaLRC();

    sm_ai_field->command = (shared_parameters.getAICommand()).c_str();

    //writing key
    *sm_ai_read_key = ai_read_key.c_str();
}

void SMMCThread::updateCommOutputSettings(void)
{
    std::cout << std::endl << "Outputting Comm settings" << std::endl << std::endl;
    //no comm settings to be output for now
    *sm_comm_read_key = comm_read_key.c_str();
}

void SMMCThread::updateAIFromVision(void)
{
    //sending variables from Vision to AI
    AIField sp_ai_field = shared_parameters.getAIField();
    sm_ai_field->image_width = sp_ai_field.image_width;
    sm_ai_field->image_height = sp_ai_field.image_height;
    sm_ai_field->ball = sp_ai_field.ball;
    for(int i=0; i<N_ROBOTS; i++)
        sm_ai_field->robot[i] = *(static_cast<Entity*>(&(sp_ai_field.robot[i])));
    for(int i=0; i<N_ROBOTS; i++)
        sm_ai_field->enemy_robot[i] = sp_ai_field.enemy_robot[i];
    *sm_ai_read_key = ai_read_key.c_str();
}

void SMMCThread::updateCommFromAI(void)
{
    //sending variables from AI to Communication
    for(int i=0; i<N_ROBOTS; i++)
        sm_robot_movement[i] = shared_parameters.getRobotMovement(i);
    *sm_comm_read_key = comm_read_key.c_str();
}


void SMMCThread::run()
{
    std::cout << "SMMC thread started" << std::endl << std::endl;
    while(run_thread)
    {
        //receiving variables
        {
            std::string s(sm_vision_write_key->begin(), sm_vision_write_key->end());
            if(s == vision_write_key)
            {
                std::cout << std::endl << "Vision input update detected" << std::endl << std::endl;
                shared_parameters.readVisionParameters(*sm_vision_field);
                emit visionInputUpdate();
                emit sendVisionChangesToAI();
                *sm_vision_write_key = EMPTY_KEY;
            }
        }

        {
            std::string s(sm_ai_write_key->begin(), sm_ai_write_key->end());
            if(s == ai_write_key)
            {
                std::cout << std::endl << "AI input update detected" << std::endl << std::endl;
                shared_parameters.readAIParameters(*sm_ai_field);
                emit aiInputUpdate();
                emit sendAIChangeToComm();
                *sm_ai_write_key = EMPTY_KEY;
            }
        }

        {
            std::string s(sm_comm_write_key->begin(), sm_comm_write_key->end());
            if(s == comm_write_key)
            {
                //no comm parameters to be recieved for now
                std::cout << std::endl << "Comm input update detected" << std::endl << std::endl;
                emit commInputUpdate();
                *sm_comm_write_key = EMPTY_KEY;
            }
        }
        usleep(50);
    }
    std::cout << "SMMC thread ended" << std::endl << std::endl;
}

#include "moc_smmcthread.cpp"
