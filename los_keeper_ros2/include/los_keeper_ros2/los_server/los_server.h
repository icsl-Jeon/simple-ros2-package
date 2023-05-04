#ifndef HEADER_LOS_SERVER
#define HEADER_LOS_SERVER
#include "los_keeper/wrapper/wrapper.h"
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <chrono>
using namespace std::chrono_literals;

namespace los_keeper {
class LosServer : public rclcpp::Node {
private:
  Wrapper wrapper_;

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;

public:
  LosServer();
  bool Update();
  void TimerCallback();
};

} // namespace los_keeper
#endif /* HEADER_LOS_SERVER */
