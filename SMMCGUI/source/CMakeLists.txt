set(LIB_HEADERS
  ../include/SMMCGUI.hpp
  ../include/GUI/mainwindow.hpp
)

set(LIB_SOURCES
  ../source/SMMCGUI.cpp
  ../source/GUI/mainwindow.cpp
)

set(APP_SOURCES
  GUI/mainwindow.cpp
  SMMCGUI.cpp
  main.cpp
)

set(APP_LIBRARY_NAME smmcgui)

add_library(${APP_LIBRARY_NAME} SHARED ${LIB_SOURCES})

set_target_properties(${APP_LIBRARY_NAME} PROPERTIES
  VERSION ${VERSION}
  FRAMEWORK FALSE
  PUBLIC_HEADER "${LIB_HEADERS}"
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
#set_property(TARGET Qt5::Core APPEND PROPERTY INTERFACE_COMPILE_OPTIONS -fPIC)

#set(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_RELEASE} -fprofile-arcs -ftest-coverage")

#set_target_properties(Qt5::Core PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")

include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${Qt5Core_INCLUDE_DIRS})

set(APPLICATION_NAME SMMCGUI)
add_executable(${APPLICATION_NAME} ${APP_SOURCES})

target_link_libraries(${APPLICATION_NAME} Qt5::Widgets ${APP_LIBRARY_NAME})

add_subdirectory(GUI)
add_subdirectory(SMMC)
