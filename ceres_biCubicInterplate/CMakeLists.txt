cmake_minimum_required(VERSION 2.8)
project(ceres_bicubicinterplate)

add_definitions(-std=c++11)

find_package(Eigen3)
if(NOT EIGEN3_FOUND)
  # Fallback to cmake_modules
  find_package(cmake_modules REQUIRED)
  find_package(Eigen REQUIRED)
  set(EIGEN3_INCLUDE_DIRS ${EIGEN_INCLUDE_DIRS})
  set(EIGEN3_LIBRARIES ${EIGEN_LIBRARIES})  # Not strictly necessary as Eigen is head only
  # Possibly map additional variables to the EIGEN3_ prefix.
else()
  set(EIGEN3_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIR})
endif()
find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})

add_executable(ceres_bicubicinterplate main.cpp)
target_link_libraries(ceres_bicubicinterplate ${CERES_LIBRARIES})

install(TARGETS ceres_bicubicinterplate RUNTIME DESTINATION bin)
