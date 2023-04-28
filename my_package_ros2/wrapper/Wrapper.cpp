#include "wrapper/Wrapper.hpp"

Wrapper::Wrapper() : Node("wrapper") {
  using namespace std::chrono_literals;
  timer_ = create_wall_timer(500ms, std::bind(&Wrapper::TimerCallback, this));
  publisher_ = create_publisher<std_msgs::msg::Float64>("simple_topic", 10);
};

void Wrapper::TimerCallback() {
  double a_variable = class_a_.GetVariable();
  double b_variable = class_b_.GetVariable();
  auto msg = std_msgs::build<std_msgs::msg::Float64>().data(b_variable);
  publisher_->publish(msg);
  RCLCPP_INFO(this->get_logger(), "Publishing: '%f'", msg.data);
}