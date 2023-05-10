cmake_minimum_required(VERSION 3.5)

project(AdvancedProg LANGUAGES CXX)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AdvancedProg_4_1 Task4_1/Task4_1.cpp)
add_executable(AdvancedProg_4_2 Task4_2/Task4_2.cpp)


add_subdirectory(Catch2 Catch2-build)
add_executable(tests_4_1 Task4_1/test.cpp)
target_link_libraries(tests_4_1 PRIVATE Catch2::Catch2)

add_executable(tests_4_2 Task4_2/test.cpp)
target_link_libraries(tests_4_2 PRIVATE Catch2::Catch2)


add_executable(AdvancedProg_1_1 Task1_1/Task1.cpp)
add_executable(AdvancedProg_1_2 Task1_2/Task2.cpp)
add_executable(AdvancedProg_1_3 Task1_3/Task1_3.cpp)
add_executable(AdvancedProg_2_1 Task2_1/Task2_1.cpp)
add_executable(AdvancedProg_3_1 Task3_1/Task3_1.cpp)
add_executable(AdvancedProg_3_2 Task3_2/Task3_2.cpp)
add_executable(AdvancedProg_5_1 Task5_1/Task5_1.cpp)
add_executable(AdvancedProg_5_2 Task5_2/Task5_2.cpp)
add_executable(AdvancedProg_5_3 Task5_3/Task5_3.cpp)
add_executable(AdvancedProg_6_1 Task6_1/Task6_1.cpp)
add_executable(AdvancedProg_6_2 Task6_2/Task6_2.cpp)

add_executable(AdvancedProg_6_3 Task6_3/Task6_3.cpp)
add_library(MyVector SHARED Task6_3/MyVector.cpp)
target_link_libraries(AdvancedProg_6_3 MyVector)

add_executable(AdvancedProg_7_1 Task7_1/Task7_1.cpp)
add_executable(AdvancedProg_7_2 Task7_2/Task7_2.cpp)
add_executable(AdvancedProg_8_1 Task8_1/Task8_1.cpp)
add_executable(AdvancedProg_8_2 Task8_2/Task8_2.cpp)

add_executable(AdvancedProg_8_3 Task8_3/Task8_3.cpp)
add_library(MyUniquePtr SHARED Task8_3/MyUniquePtr.cpp)
target_link_libraries(AdvancedProg_8_3 MyUniquePtr)

add_executable(AdvancedProg_9_1 Task9_1/Task9_1.cpp)
add_executable(AdvancedProg_9_2 Task9_2/Task9_2.cpp)











