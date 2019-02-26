#include "Vard.hpp"

Vard::Vard(const char* arg1, const char* arg2, const char* arg3):
write_key(arg1), read_key(arg2), shutdown_key(arg3)
{
    QString a = qApp->applicationDirPath();
    #ifndef XBEE
        a += "/../../source/robots_settings.txt";
    #else
        a += "/../../source/robots_settings_xbee.txt";
    #endif
    robot_settings.open(a.toStdString());
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
            robot.push_back(Robot(getRobotNameFromFile(aux), getRobotRFAddressFromFile(aux)));
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
            serial_comm->mountPacket(robot[i].getName(), robot[i].getRFAddress(), robot[i].getVelX(), robot[i].getVelY(), robot[i].getVelAng());
            //std::cout <<"robo: " << robot[i]->getName() << ", endr: " << robot[i]->getRFAddress() <<", x: "<<robot[i]->getVelX()<<", y: "<< robot[i]->getVelY()<<", ang: "<< robot[i]->getVelAng() <<std::endl;
            serial_comm->sendData();
            usleep(COMMUNICATION_DELAY);
        }

    }
}

int Vard::getRobotNameFromFile(std::string str)
{
    std::size_t pos = str.find(":");
    std::string str_dec = str.substr(pos+1, str.size());
    int name = std::stoi (str_dec);
    return name;
}

std::string Vard::getRobotRFAddressFromFile(std::string str)
{
    std::size_t pos = str.find("@");
    str = str.substr(pos+1, str.size());
    //char *rf_address = (char*)str.c_str();
    return str;
}
