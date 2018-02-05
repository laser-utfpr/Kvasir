set(LIB_HEADERS
  ../include/SMMCGUI.hpp
)

set(LIB_SOURCES
  ../source/SMMCGUI.cpp
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

set(APPLICATION_NAME SMMCGUI)
add_executable(${APPLICATION_NAME} ${APP_SOURCES})

add_subdirectory(GUI)
add_subdirectory(SMMC)
