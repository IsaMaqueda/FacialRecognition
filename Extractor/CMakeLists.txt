cmake_minimum_required(VERSION 3.1)
# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(OpenCV REQUIRED)

# I../includes
include_directories(includes)
include_directories(${OpenCV_INCLUDE_DIRS})

# puts all .cpp files inside src to the SOURCES variable
file(GLOB SOURCES src/*.cpp)

include(/home/egcb/Documents/dlib-19.17/dlib/cmake)

add_executable(main ${SOURCES})
target_link_libraries(main ${OpenCV_LIBS} dlib::dlib)
