#include <iostream>
#include <ceres/cubic_interpolation.h>

// struct Grid2D {
//   enum { DATA_DIMENSION = 2 };
//   void GetValue(int row, int col, double* f) const;
// };
// 

using namespace std;

int main(int argc, char **argv) {
  
  const double data[] = {1.0, 3.0, -1.0, 4.0, 3.6, 2.1, 4.2, 2.0, 2.0, 1.0, 3.1, 5.2};
  const double data_1[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  ceres::Grid2D<double,1> array(data, 0, 3, 0, 4);
  ceres::Grid2D<double,1> array_1(data_1, 0, 3, 0, 4);
  ceres::BiCubicInterpolator<ceres::Grid2D<double,1>> interpolator(array);
  ceres::BiCubicInterpolator<ceres::Grid2D<double,1>> interpolator_1(array_1);
  double f, dfdr, dfdc;
//   interpolator.Evaluate(1.2, 2.5, &f, &dfdr, &dfdc);
  interpolator_1.Evaluate(1.2, 2.5, &f, &dfdr, &dfdc);
  
  cout << f << ' ' << dfdc << ' ' << dfdr << endl;
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
