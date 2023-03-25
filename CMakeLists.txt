cmake_minimum_required(VERSION 3.5)

project(AdvancedProg LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AdvancedProg Task1_1/Task1.cpp)

install(TARGETS AdvancedProg
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
