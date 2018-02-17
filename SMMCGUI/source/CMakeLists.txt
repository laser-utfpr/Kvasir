set(APP_HEADERS
  ${HEADER_DIR}/SMMCGUI.hpp
  ${HEADER_DIR}/GUI/mainwindow.hpp
)

#set(UI_LINKED_HEADERS
#  ${HEADER_DIR}/GUI/mainwindow.hpp
#)

set(APP_SOURCES
  ${SOURCE_DIR}/GUI/mainwindow.cpp
  ${SOURCE_DIR}/SMMCGUI.cpp
  ${SOURCE_DIR}/main.cpp
)

set(APP_FORMS
  ${FORMS_DIR}/mainwindow.ui
)

#qt5_wrap_cpp(QT_WRAPPED_HEADERS ${UI_LIKED_HEADERS})
#qt5_wrap_ui(QT_WRAPPED_FORMS ${APP_FORMS})

set(APPLICATION_NAME SMMCGUI)
#add_executable(${APPLICATION_NAME} ${APP_SOURCES} ${QT_WRAPPED_FORMS} ${QT_WRAPPED_HEADERS})
add_executable(${APPLICATION_NAME} ${APP_SOURCES})

target_link_libraries(${APPLICATION_NAME} Qt5::Widgets)

add_subdirectory(GUI)
add_subdirectory(SMMC)
