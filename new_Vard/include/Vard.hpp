//biblioteca feita para coordenacao das componentes de Vard

#ifndef _VARD_HPP_
#define _VARD_HPP_
#include <string>
#include <iostream>
#include <fstream>
#include <smmclib.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/allocators/allocator.hpp>

class Vard{
    std::string write_key;
    std::string read_key;
    std::string shutdown_key;
    ofstream robot_settings;
    SerialCommunication *serial_comm;
    Robot* robot[N_ROBOTS];
    boost::interprocess::managed_shared_memory *shared_memory;

    int getRobotNameFromFile(std::string str);
    char *getRobotRFAddressFromFile(std::string str);
public:
    Vard(const char* arg1, const char* arg2, const char* arg3);
    ~Vard();
    void start();

};
#endif
