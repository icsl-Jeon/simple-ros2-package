#ifndef HEADER_TARGET_MANAGER
#define HEADER_TARGET_MANAGER
#include "los_keeper/obstacle_manager/obstacle_manager.h"
#include <Eigen/Core>
#include <string>

namespace los_keeper {

class TargetManager {
private:
  std::string name_{"TargetManager"};

public:
  std::string GetName() const;
  bool CheckCollision(const ObstacleManager &obstacle_manager) const;
};
} // namespace los_keeper

#endif /* HEADER_TARGET_MANAGER */
