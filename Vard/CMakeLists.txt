project(Vard)
cmake_minimum_required(VERSION 2.8)

#aux_source_directory(. SRC_LIST)

#aux_source_directory(relacaoRobos/ SRC_LIST)
#aux_source_directory(radio/ SRC_LIST)
#aux_source_directory(listaEncadeada/ SRC_LIST)
#aux_source_directory(display/ SRC_LIST)
#add_executable(${PROJECT_NAME} ${SRC_LIST})

set(APP_SOURCES
	main.cpp
	Principal.cpp
	relacaoRobos/RelacaoRobos.cpp
	radio/Radio.cpp
	radio/rs232.c
	radio/SerialPacket.cpp
	listaEncadeada/ListaRobos.cpp
	listaEncadeada/Robo.cpp
	listaEncadeada/VelocitiesLoader.cpp
)

add_executable(${PROJECT_NAME} ${APP_SOURCES})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_package(PkgConfig)
pkg_check_modules(smmclib REQUIRED smmclib)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} Threads::Threads)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} rt)
target_link_libraries(${PROJECT_NAME} smmclib)
