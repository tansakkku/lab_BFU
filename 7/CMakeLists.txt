cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME lab_7)
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("inc/")

add_executable("${PROJECT_NAME}" 6.1.cpp
					inc/Header.hpp

					src/Source.cpp

					input/input.txt
)

