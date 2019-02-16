#include "Vard.hpp"

Vard::Vard(const char* arg1, const char* arg2, const char* arg3):
write_key(arg1), read_key(arg2), shutdown_key(arg3)
{
    robot_settings.open("robots_settings.txt");
    serial_comm = new SerialCommunication();
    if(robot_settings.is_open())
    {
        int i = 0;
        while(!robot_settings.fail() && i < N_ROBOTS)
        {
            std::string aux;
            std::getline (robot_settings, aux);
            std::size_t pos = aux.find("#");//comentario
            while(pos != std::string::npos && !robot_settings.fail())
            {
                std::getline (robot_settings, aux);
                pos = aux.find("#");
            }
            robot[i] = new Robot(getRobotNameFromFile(aux), getRobotRFAddressFromFile(aux));
            i++;
        }
        robot_settings.close();
    }
    else
    {
        std::cout << std::endl << "Exception while opening file of settings:" << std::endl;
        exit(1);
    }
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
}

Vard::~Vard()
{
    delete serial_comm;
    for(int i=0; i < N_ROBOTS; i++)
    {
        delete robot[i];
    }
    if(shared_memory != NULL)
        delete shared_memory;

    boost::interprocess::shared_memory_object::remove(SHARED_MEMORY_BLOCK_NAME);
}

void Vard::start()
{
    BoostInterprocessString *mem_write_key;
    BoostInterprocessString *mem_read_key;
    BoostInterprocessString *mem_shutdown_key;
    try
    {
        mem_write_key = (shared_memory->find<BoostInterprocessString>(COMM_WRITE_KEY_MEMORY_NAME)).first;
        mem_read_key = (shared_memory->find<BoostInterprocessString>(COMM_READ_KEY_MEMORY_NAME)).first;
        mem_shutdown_key = (shared_memory->find<BoostInterprocessString>(COMM_SHUTDOWN_KEY_MEMORY_NAME)).first;
    }
    catch(const std::exception& e)
    {
        std::cout << std::endl << "Exception called while acessing shared memory keys:" << std::endl;
        std::cout << e.what() << std::endl;
        exit(1);
    }
    while(*mem_shutdown_key != shutdown_key.c_str())
    {
        for(int i=0; i<N_ROBOTS; i++)
        {
            serial_comm->mountPacket(robot[i]->getName(), robot[i]->getRFAddress(), robot[i]->getVelX(), robot[i]->getVelY(), robot[i]->getVelAng());
            serial_comm->sendData();
        }
    }
}

int Vard::getRobotNameFromFile(std::string str)
{
    std::string::size_type sz;
    int name = std::stoi (str, &sz);
    return name;
}

char *Vard::getRobotRFAddressFromFile(std::string str)
{
    char *rf_address;
    std::size_t pos = str.find("@");
    str.copy(rf_address, str.size()-(pos+1), pos+1);
    return rf_address;
}
