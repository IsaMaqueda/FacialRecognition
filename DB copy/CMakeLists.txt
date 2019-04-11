#
# This is a CMake makefile.  You can find the cmake utility and
# information about it at http://www.cmake.org
#

cmake_minimum_required (VERSION 3.1)
project(fr)

set (CMAKE_CXX_STANDARD 11)


 set(SOURCE DataBase.cpp	
    )
   
 set(HEADERS	DataBase.h
    )

# automatic OpenCV finding
find_package(OpenCV REQUIRED) 

# if not, use manual specification of the OpenCVConfig.cmake path
# and comment previous line of automatic finding
#find_package(OpenCV REQUIRED PATHS /usr/local/share/OpenCV NO_DEFAULT_PATH) 


if(OpenCV_FOUND)
	message("-- Opencv Found")
endif()



add_executable(fr main.cpp ${SOURCE} ${HEADERS})
target_link_libraries(fr ${OpenCV_LIBS})