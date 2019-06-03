# only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# project name
project(FaceAligner)


include(./dlib-19.17/dlib/cmake)
# sets opencv home dir
find_package(OpenCV REQUIRED)
message("STATUS: " ${OpenCV_LIBS})
message("STATUS: " ${OpenCV_DIR})
message("STATUS: " ${OpenCV_INCLUDE_DIRS})

set(EXEC main)


set(CMAKE_CXX_STANDARD 11)

# I../includes
include_directories(includes)
include_directories(${OpenCV_INCLUDE_DIRS})

# puts all .cpp files inside src to the SOURCES variable
file(GLOB SOURCES src/*.cpp)

# compiles the files defined by SOURCES to generante the executable defined by EXEC
add_executable(${EXEC} ${SOURCES})
target_link_libraries(${EXEC} ${OpenCV_LIBS} dlib::dlib)
