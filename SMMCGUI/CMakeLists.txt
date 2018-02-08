project(SMMCGUI)

cmake_minimum_required(VERSION 3.0.2)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/SMMC
    ${PROJECT_SOURCE_DIR}/include/GUI
    ${PROJECT_SOURCE_DIR}/forms
    ${PROJECT_BINARY_DIR}/include
)

set(VERSION 0.0.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

enable_testing()
add_subdirectory(include)
add_subdirectory(source)
add_subdirectory(forms)
