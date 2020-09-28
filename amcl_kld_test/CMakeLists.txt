cmake_minimum_required(VERSION 2.6)
project(amcl_kld_test)

add_executable(amcl_kld_test main.cpp)

install(TARGETS amcl_kld_test RUNTIME DESTINATION bin)
