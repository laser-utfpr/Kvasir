project(BoostSerializationTest)

#CMake version should be > 3.9 for CMAKE_AUTOUIC_SEARCH_PATHS
cmake_minimum_required(VERSION 3.9.0)
#Setting C++ version to C++11
set(CMAKE_CXX_STANDARD 11)

#Setting build type to release
set(CMAKE_BUILD_TYPE Release)

#Setting directory for the outputted executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

#Including Boost
find_package(Boost COMPONENTS serialization REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

#Including pthread
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

#Creating the executable
set(APPLICATION_NAME BoostSerializationTest)
add_executable(${APPLICATION_NAME} main.cpp)

target_link_libraries(${APPLICATION_NAME} Boost::serialization)
target_link_libraries(${APPLICATION_NAME} Threads::Threads)
target_link_libraries(${APPLICATION_NAME} rt)

add_subdirectory(include)
add_subdirectory(source)
add_subdirectory(forms)
