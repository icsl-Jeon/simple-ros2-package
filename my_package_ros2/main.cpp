#include "rclcpp/rclcpp.hpp"
#include "wrapper/Wrapper.hpp"

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Wrapper>());

  rclcpp::shutdown();
  return 0;
}