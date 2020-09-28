cmake_minimum_required(VERSION 2.6)
project(cluster)

add_executable(cluster main.cpp)

install(TARGETS cluster RUNTIME DESTINATION bin)
