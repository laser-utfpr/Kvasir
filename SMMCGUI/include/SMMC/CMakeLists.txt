#Creating the SMMC variables library
set(SMMC_LIB_NAME smmclib)

include(GNUInstallDirs)

add_library(${SMMC_LIB_NAME} SHARED)

configure_file(smmclib.pc.in smmclib.pc @ONLY)

set_target_properties(${SMMC_LIB_NAME} PROPERTIES PUBLIC_HEADER smmclib.hpp)

target_include_directories(${SMMC_LIB_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS ${SMMC_LIB_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${CMAKE_BINARY_DIR}/include/SMMC/smmclib.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

install(FILES aifield.hpp coloredobject.hpp coord.hpp entity.hpp movement.hpp player.hpp smmcconstants.h visionfield.hpp
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
