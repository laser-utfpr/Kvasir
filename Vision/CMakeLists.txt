project(Vision)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/libs/opencv-install/lib/pkgconfig")
set(ENV{PKG_CONFIG_PATH}  "${CMAKE_SOURCE_DIR}/libs/opencv-install/lib/pkgconfig")

find_package(PkgConfig REQUIRED)
pkg_search_module(PKG_OPENCV REQUIRED opencv)
include_directories(${PKG_OPENCV_INCLUDE_DIRS})
target_link_libraries (Vision ${PKG_OPENCV_LDFLAGS})
