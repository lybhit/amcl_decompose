#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "amcl/map/map.h"

using namespace std;

struct OccupancyGrid{
  uint32_t width;
  uint32_t height;
  float resolution;
  int8_t* data;
};

int main(int argc, char **argv) {
  struct OccupancyGrid grid;
  grid.width = 40;
  grid.height  = 40;
  grid.resolution = 0.05;
  grid.data = new int8_t[grid.height * grid.width];
  
  for(int i = 0; i < grid.width*grid.height; ++i)
  {
    grid.data[i] = 6;
  }
  
  for(int i = 0; i < grid.width; ++i)
  {
    grid.data[i] = 100;
  }
  
  for(int j = 0; j < grid.height; ++j)
  {
    grid.data[j*grid.width] = 100;
  }
  
  map_t* map = map_alloc();
  map->size_x = grid.width;
  map->size_y = grid.height;
  map->origin_x = 0.0;
  map->origin_y = 0.0;
  map->scale = grid.resolution;
  
  map->cells = (map_cell_t*)malloc(sizeof(map_cell_t)*map->size_x*map->size_y);
  
  for(int i=0;i<map->size_x * map->size_y;i++)
  {
    if(grid.data[i] == 0)
      map->cells[i].occ_state = -1;
    else if(grid.data[i] == 100)
      map->cells[i].occ_state = +1;
    else
      map->cells[i].occ_state = 0;
  }
  
  double max_occ_dist = 1.5;
  map_update_cspace(map,max_occ_dist);
  
  cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
  cout.setf(std::ios_base::showpoint);
  
  for(int i = 0; i < map->size_y; ++i)
  {
    for(int j = 0; j < map->size_x; ++j)
    {
      cout << setw(4)<< setprecision(3)<<map->cells[MAP_INDEX(map, i, j)].occ_dist << ' ';
    }
    
    cout << endl;
  }
  
  delete[] grid.data;
  
  
  return 0;
}





























