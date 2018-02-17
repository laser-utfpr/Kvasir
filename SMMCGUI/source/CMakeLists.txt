#Defining the executable's sources
set(APP_SOURCES
  ${SOURCE_DIR}/GUI/mainwindow.cpp
  ${SOURCE_DIR}/SMMCGUI.cpp
  ${SOURCE_DIR}/main.cpp
)

#Creating the executable
set(APPLICATION_NAME SMMCGUI)
add_executable(${APPLICATION_NAME} ${APP_SOURCES})

#Linking external libraries to the executable
target_link_libraries(${APPLICATION_NAME} Qt5::Widgets)
target_link_libraries(${APPLICATION_NAME} ${OpenCV_LIBS})
target_link_libraries(${APPLICATION_NAME} Threads::Threads)
target_link_libraries(${APPLICATION_NAME} rt)

add_subdirectory(GUI)
add_subdirectory(SMMC)
