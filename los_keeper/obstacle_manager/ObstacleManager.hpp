#ifndef HEADER_OBSTACLEMANAGER
#define HEADER_OBSTACLEMANAGER
#include <Eigen/Core>
#include <Eigen/Geometry>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

namespace los_keeper {
class ObstacleManager {
private:
  pcl::PointCloud<pcl::PointXYZ> cloud_;
  Eigen::Affine3d pose_;
};
} // namespace los_keeper
#endif /* HEADER_OBSTACLEMANAGER */
