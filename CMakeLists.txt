cmake_minimum_required(VERSION 2.8)

project(autocar)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 1)
set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

set(CMAKE_CXX_FLAGS "-std=c++11")

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

find_package(OpenCV REQUIRED)

set(CURRENT_PROJET_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CURRENT_PROJET_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CURRENT_PROJET_DIR}/build/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CURRENT_PROJET_DIR}/build/lib)

include_directories(
    /usr/local/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)

add_executable(autocar 
    "main.cc"
    "task1.cc"
    "task2.cc"
    "my_serial.cc"
    "LinuxSerial.cc"
)

target_link_libraries(autocar 
    ${OpenCV_LIBRARIES}
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/libzbar.so.0
)
