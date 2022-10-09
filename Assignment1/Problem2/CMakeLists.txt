cmake_minimum_required(VERSION 3.23)
project(Problem2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Problem2
        src/main.cpp include/Student.h include/File.h include/VerifyData.h include/ManageData.h)
