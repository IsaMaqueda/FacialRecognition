cmake_minimum_required(VERSION 3.1)
# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include(/home/pablo/Documents/dlib-19.17/dlib/cmake)

# find_package(OpenCV REQUIRED)
SET(OpenCV_DIR /home/pablo/opencv/build)
find_package(OpenCV REQUIRED PATHS /home/pablo/opencv/build)

add_executable(fr main.cpp)
target_link_libraries(fr ${OpenCV_LIBS} dlib::dlib)
