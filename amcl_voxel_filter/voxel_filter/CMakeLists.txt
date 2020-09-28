cmake_minimum_required(VERSION 2.8.3)
project(voxel_filter)

find_package(Ceres REQUIRED)

include_directories(include ${CERES_INCLUDE_DIRS})


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

add_library(cloud_voxel_filter SHARED 
            src/voxel_filter_simple.cpp) 

add_executable(cloud_filter src/main.cpp)
target_link_libraries(cloud_filter cloud_voxel_filter)

#install_targets(TARGETS cloud_voxel_filter
#                RUNTIME DESTINATION bin
#                ARCHIVE DESTINATION bin
#                LIBRARY DESTINATION bin
#)
                
#install_targets(TARGETS cloud_filter
#                RUNTIME DESTINATION bin
#)
