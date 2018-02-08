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

set(FORMS
  ../forms/mainwindow.ui
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

set(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_RELEASE} -fprofile-arcs -ftest-coverage")

set_target_properties(Qt5::Core PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")

include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${Qt5Core_INCLUDE_DIRS})

qt5_wrap_cpp(HEADERS_MOC ${LIB_HEADERS})

set(APPLICATION_NAME SMMCGUI)
add_executable(${APPLICATION_NAME} ${APP_SOURCES} ${FORMS_HEADERS} ${HEADERS_MOC})

target_link_libraries(${APPLICATION_NAME} Qt5::Widgets)

add_subdirectory(GUI)
add_subdirectory(SMMC)
