cmake_minimum_required(VERSION 2.8)
project(map_analyze)

include_directories(include)

add_library(amcl_map SHARED
            src/amcl/map/map.c
            src/amcl/map/map_draw.c
            src/amcl/map/map_cspace.cpp
            src/amcl/map/map_range.c
            src/amcl/map/map_store.c)
            
add_executable(map_analyze main.cpp)
target_link_libraries(map_analyze amcl_map)

install(TARGETS map_analyze RUNTIME DESTINATION bin)

install(TARGETS amcl_map 
     RUNTIME DESTINATION bin
     ARCHIVE DESTINATION bin
     LIBRARY DESTINATION bin
)
