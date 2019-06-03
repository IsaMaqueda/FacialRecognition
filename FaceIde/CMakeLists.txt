#
# This is a CMake makefile.  You can find the cmake utility and
# information about it at http://www.cmake.org
#

cmake_minimum_required (VERSION 3.1)
project(far)

set (CMAKE_CXX_STANDARD 11)


 set(SOURCE DataBase.cpp FaceIdentification.cpp	
    )
   
 set(HEADERS	DataBase.h FaceIdentification.h
    )

# automatic OpenCV finding
find_package(OpenCV REQUIRED) 

# if not, use manual specification of the OpenCVConfig.cmake path
# and comment previous line of automatic finding
#find_package(OpenCV REQUIRED PATHS /usr/local/share/OpenCV NO_DEFAULT_PATH) 


if(OpenCV_FOUND)
	message("-- Opencv Found")
endif()



add_executable(far main.cpp ${SOURCE} ${HEADERS})
target_link_libraries(far ${OpenCV_LIBS})