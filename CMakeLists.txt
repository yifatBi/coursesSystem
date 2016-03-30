cmake_minimum_required(VERSION 3.3)
project(tirgul4_ex_and_sol)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Journal.cpp Journal.h Research_Title.cpp Research_Title.h Title.h Workbook_Title.cpp Title.cpp Workbook_Title.h BookTitle.h BookTitle.cpp Student.cpp Student.h Course.cpp Course.h)
add_executable(tirgul4_ex_and_sol ${SOURCE_FILES})