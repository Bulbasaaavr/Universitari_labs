cmake_minimum_required(VERSION 3.22) 

set(PROJECT_NAME OPLaba11)
project("${PROJECT_NAME}")	

set(CMAKE_CXX_STANDARD 17)			
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_executable("${PROJECT_NAME}" OPLaba11.cpp
)