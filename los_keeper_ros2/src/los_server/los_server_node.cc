#include "los_keeper_ros2/los_server/los_server.h"

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<los_keeper::LosServer>());

  rclcpp::shutdown();
  return 0;
}