#include "vor.hpp"

Vor::Vor(std::string wk, std::string rk, std::string sk) :
               write_key(wk), read_key(rk), shutdown_key(sk),
               provider_name("vorallocatorprovider")
{
    try
    {
        shared_memory = new boost::interprocess::managed_shared_memory(boost::interprocess::open_only,
                                                                       SHARED_MEMORY_BLOCK_NAME);
    }
    catch(const std::exception& e)
    {
        std::cout << std::endl << "Exception called while opening shared memory block:" << std::endl;
        std::cout << e.what() << std::endl;
        exit(1);
    }

    boost::interprocess::shared_memory_object::remove(provider_name.c_str());
    allocator_provider = new boost::interprocess::managed_shared_memory(boost::interprocess::create_only, provider_name.c_str(), SHARED_MEMORY_SIZE);

    char_allocator = new CharAllocator(allocator_provider->get_segment_manager());
    string_allocator = new StringAllocator(allocator_provider->get_segment_manager());
    ai_field_handler = new AIFieldHandler(*char_allocator, *string_allocator);

    strategy = new Strategy(*ai_field_handler);
}

Vor::~Vor()
{
    if(ai_field_handler != nullptr)
        delete ai_field_handler;
    if(char_allocator != nullptr)
        delete char_allocator;
    if(string_allocator != nullptr)
        delete string_allocator;
    if(allocator_provider != nullptr)
        delete allocator_provider;

    if(shared_memory != nullptr)
        delete shared_memory;

    boost::interprocess::shared_memory_object::remove(provider_name.c_str());
}

int Vor::runVor(void)
{
    BoostInterprocessString *sm_write_key;
    BoostInterprocessString *sm_read_key;
    BoostInterprocessString *sm_shutdown_key;
    try
    {
        sm_write_key = (shared_memory->find<BoostInterprocessString>(AI_WRITE_KEY_MEMORY_NAME)).first;
        sm_read_key = (shared_memory->find<BoostInterprocessString>(AI_READ_KEY_MEMORY_NAME)).first;
        sm_shutdown_key = (shared_memory->find<BoostInterprocessString>(AI_SHUTDOWN_KEY_MEMORY_NAME)).first;
    }
    catch(const std::exception& e)
    {
        std::cout << std::endl << "Vor got an exception called while acessing shared memory keys:" << std::endl;
        std::cout << e.what() << std::endl;
        exit(1);
    }

    strategy->makeCommandList();
    ai_field_handler->writeChanges(*shared_memory);
    *sm_write_key = write_key.c_str();

    ai_field_handler->readChanges(*shared_memory);

    while(*sm_shutdown_key != shutdown_key.c_str())
    {
        if(*sm_read_key == read_key.c_str())
        {
            std::cout << "Vor received read signal, reading settings from the shared memory" << std::endl;
            *sm_read_key = EMPTY_KEY;
            ai_field_handler->readChanges(*shared_memory);
        }
        if(ai_field_handler->sampleTime() != last_sample_time)
        {
            strategy->calculateVelocities();
            std::cout << "Vor calculated velocities, writing ai field into the shared memory" << std::endl;
            ai_field_handler->writeChanges(*shared_memory);
            *sm_write_key = write_key.c_str();
            last_sample_time = ai_field_handler->sampleTime();
        }
    }

    std::cout << "Vor Received Shutdown Signal" << std::endl;

    return 0;
}
