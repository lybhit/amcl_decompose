#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string.h>

#include "voxel_filter_simple.h"

int main(int argc, char** argv)
{
  double voxel_max_length  = atof(argv[1]);
  double voxel_max_range = atof(argv[2]);
  double voxel_min_num_points = atof(argv[3]);
  cartographer::sensor::AdaptiveVoxelFilterOptions options;
  options = cartographer::sensor::CreateAdaptiveVoxelFilterOptions(voxel_max_length, voxel_max_range, voxel_min_num_points);
  
  cartographer::sensor::AdaptiveVoxelFilter adaptive_voxel_filter(options);
  
  PointCloud points;
  
  std::ifstream infile;
  
  infile.open("filtered_points.txt");
  if(!infile.is_open())
  {
    std::cout << "open file failure" << std::endl;
  }
  
  while(!infile.eof())
  {
    double x, y;
    infile >> x >> y;
    Eigen::Vector3f point(x,y,0.);
    points.push_back(point);
    
  }
  
  infile.close();
  
  const PointCloud filtered_gravity_aligned_point_cloud = adaptive_voxel_filter.Filter(points);
  
  std::ofstream outfile;
  
  char a[20], b[20], c[20], dst[60];
  
  strcpy(a, "filtered_points_");
  strcpy(b, argv[3]);
  strcpy(c, ".txt");
  
  strcat(dst,strcat(strcat(a,b),c));
  
  
  outfile.open(dst, std::ios::app);
  
  int len = filtered_gravity_aligned_point_cloud.size(); 
  
  for(int i = 0; i < len; ++i)
  {
    outfile << filtered_gravity_aligned_point_cloud[i].x() << ' ' << filtered_gravity_aligned_point_cloud[i].y() << '\n'; 
  }
  
  outfile.close();
  
  return 0;
  
}
