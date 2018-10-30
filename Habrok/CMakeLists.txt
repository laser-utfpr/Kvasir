project(Habrok)

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

#Defining useful directory macros
set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(FORMS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/forms)

#Including the project's headers directories
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_BINARY_DIR}/include
)

#Including smmc-lib
find_package(PkgConfig)
pkg_check_modules(smmclib REQUIRED smmclib)

#Including Qt5
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${Qt5Core_INCLUDE_DIRS})
#Setting options for the project's Qt5 stuff to be compiled correctly
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${FORMS_DIR})

#Including OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIR})

#Including Boost
find_package(Boost COMPONENTS serialization system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

#Including pthread
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_subdirectory(include)
add_subdirectory(source)
add_subdirectory(forms)
