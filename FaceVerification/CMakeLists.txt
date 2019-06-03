cmake_minimum_required (VERSION 3.1)
project(FaceVerification)

set (CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES src/*.cpp)
include_directories(includes)

find_package(OpenCV REQUIRED) 

add_executable(main ${SOURCES})
target_link_libraries(main ${OpenCV_LIBS})