#include <iostream>
#include <stdlib.h>
#include <math.h>
//#include <unordered_map>

#include "ros/ros.h"
#include "geometry_msgs/Pose.h"

using namespace std;

typedef struct _pf_t{
  int max_samples;
  int min_samples; 
  double pop_z;
  double pop_err;
}pf_t;

int pf_resample_limit(pf_t *pf, int k)
{
  double a, b, c, x;
  int n;

  if (k <= 1)
    return pf->max_samples;

  a = 1;
  b = 2 / (9 * ((double) k - 1));
  c = sqrt(2 / (9 * ((double) k - 1))) * pf->pop_z;
  x = a - b + c;

  n = (int) ceil((k - 1) / (2 * pf->pop_err) * x * x * x);

  if (n < pf->min_samples)
    return pf->min_samples;
  if (n > pf->max_samples)
    return pf->max_samples;
  
  return n;
}

void pf_kdtree_cluster_node()
{
  for(int i = 0; i < 27; i++)
  {
    int a = (i / 9) - 1;
    int b = ((i % 9) / 3) - 1;
    int c = ((i % 9) % 3) - 1;
    
//     cout << a << ' ' << b << ' ' << c << endl;
  }
}

int main(int argc, char **argv) {
  
  pf_t* pf = new pf_t;
  pf->max_samples = 5000;
  pf->min_samples = 1;
  pf->pop_err = 0.01;
  pf->pop_z = 0.99;
  
  
  for(int i = 1; i < 100; i+=5)
  {
    int num = pf_resample_limit(pf, i);
    cout << "index i = " << i << ' '<< "num = " << num << endl;
  }
  
  int tmp = pf_resample_limit(pf, 378);
  
  cout << tmp << endl;
  
  pf_kdtree_cluster_node();
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
