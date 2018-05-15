#Defining the executable's sources
set(APP_SOURCES
  main.cpp
)

#Creating the executable
set(APPLICATION_NAME Test)
add_executable(${APPLICATION_NAME} ${APP_SOURCES})

#Linking external libraries to the executable
target_link_libraries(${APPLICATION_NAME} Threads::Threads)
target_link_libraries(${APPLICATION_NAME} rt)
