#ifndef HEADER_WRAPPER
#define HEADER_WRAPPER

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

#include "my_package/library_a/LibraryA.hpp"
#include "my_package/library_b/LibraryB.hpp"
#include "visualizer/Visualizer.hpp"

class Wrapper : public rclcpp::Node {
private:
  library_a::ClassA class_a_;
  library_b::ClassB class_b_;
  visualizer::Visualizer visualizer_;

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;

public:
  Wrapper();
  void TimerCallback();
};

#endif /* HEADER_WRAPPER */
