cmake_minimum_required(VERSION 3.13)
project(LAI_JSON)

set(CMAKE_CXX_STANDARD 14)

add_executable(LAI_JSON test.cpp laijson.cpp laihzjson.h)

target_link_libraries(LAI_JSON /usr/local/lib64/libgtest.a /usr/local/lib64/libgtest_main.a -pthread)
