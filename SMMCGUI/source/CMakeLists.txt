set(LIB_HEADERS
  ../include/SMMCGUI.hpp
  ../include/mainwindow.hpp
)

set(LIB_SOURCES
  ../source/SMMCGUI.cpp
  ../source/mainwindow.cpp
)

set(APP_SOURCES
  main.cpp
  SMMCGUI.cpp
)

set(LIBRARY_NAME smmcgui)

add_library(${LIBRARY_NAME} SHARED ${LIB_SOURCES})

set_target_properties(${LIBRARY_NAME} PROPERTIES
  VERSION ${VERSION}
  FRAMEWORK FALSE
  PUBLIC_HEADER "${LIB_HEADERS}"
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(APPLICATION_NAME SMMCGUI)
add_executable(${APPLICATION_NAME} ${APP_SOURCES})

target_link_libraries(${APPLICATION_NAME} Qt5::Widgets)

add_subdirectory(GUI)
add_subdirectory(SMMC)
