#Creating the SMMC variables library
set(SMMC_LIB_NAME smmc-lib)
add_library(${SMMC_LIB_NAME} INTERFACE)
target_include_directories(${SMMC_LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
