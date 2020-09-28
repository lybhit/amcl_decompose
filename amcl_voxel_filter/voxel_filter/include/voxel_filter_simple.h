#ifndef CARTOGRAPHER_SENSOR_INTERNAL_VOXEL_FILTER_SIMPLE_H_
#define CARTOGRAPHER_SENSOR_INTERNAL_VOXEL_FILTER_SIMPLE_H_

#include <bitset>
#include <vector>
#include <unordered_set>
#include <eigen3/Eigen/Core>

typedef std::vector<Eigen::Vector3f> PointCloud;

namespace cartographer {
namespace sensor {

struct AdaptiveVoxelFilterOptions
{
  float max_length_;
  float min_num_points_;
  float max_range_;

  void set_max_length(float length)
  {
    max_length_ = length;
  }

  void set_max_range(float range)
  {
    max_range_ = range;
  }

  void set_min_num_points(float num_points)
  {
    min_num_points_ = num_points;
  }

  float min_num_points() const
  {
    return min_num_points_;
  }

  float max_range() const
  {
    return max_range_;
  }

  float max_length() const
  {
    return max_length_;
  }
};

// Voxel filter for point clouds. For each voxel, the assembled point cloud
// contains the first point that fell into it from any of the inserted point
// clouds.
class VoxelFilter {
 public:
  // 'size' is the length of a voxel edge.
  explicit VoxelFilter(float size) : resolution_(size) {}

  VoxelFilter(const VoxelFilter&) = delete;
  VoxelFilter& operator=(const VoxelFilter&) = delete;

  // Returns a voxel filtered copy of 'point_cloud'.
  PointCloud Filter(const PointCloud& point_cloud);


 private:
  using KeyType = std::bitset<3 * 32>;

  static KeyType IndexToKey(const Eigen::Array3i& index);

  Eigen::Array3i GetCellIndex(const Eigen::Vector3f& point) const;

  float resolution_;
  std::unordered_set<KeyType> voxel_set_;
};

AdaptiveVoxelFilterOptions CreateAdaptiveVoxelFilterOptions(float max_length, float max_range, float min_num_points);

class AdaptiveVoxelFilter {
 public:
  explicit AdaptiveVoxelFilter(const AdaptiveVoxelFilterOptions& options);

  AdaptiveVoxelFilter(const AdaptiveVoxelFilter&) = delete;
  AdaptiveVoxelFilter& operator=(const AdaptiveVoxelFilter&) = delete;

  PointCloud Filter(const PointCloud& point_cloud) const;

 private:
  const AdaptiveVoxelFilterOptions options_;
};

}  // namespace sensor
}  // namespace cartographer

#endif  // CARTOGRAPHER_SENSOR_INTERNAL_VOXEL_FILTER_SIMPLE_H_
