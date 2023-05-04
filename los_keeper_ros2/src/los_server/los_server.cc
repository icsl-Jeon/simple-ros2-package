#include "los_keeper_ros2/los_server/los_server.h"

using namespace los_keeper;
bool LosServer::Update() { return wrapper_.Plan(); }
void LosServer::TimerCallback() {
  if (Update()) {
    RCLCPP_INFO(this->get_logger(), "Update success by LosKeeper");
  }
}
LosServer::LosServer() : Node("los_server_node") {
  timer_ =
      this->create_wall_timer(1s, std::bind(&LosServer::TimerCallback, this));
}
