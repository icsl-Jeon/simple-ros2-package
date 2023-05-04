#include "los_keeper/obstacle_manager/obstacle_manager.h"
#include "los_keeper_ros2/los_server/los_server.h"
#include "gtest/gtest.h"
#include <Eigen/Core>

namespace los_keeper {

TEST(LosServerTest, IsObstacleManagerIncludedAutomatically) {

  ObstacleManager obstacle_manager;
  EXPECT_EQ(obstacle_manager.GetName(), "ObstacleManager");
}

} // namespace los_keeper