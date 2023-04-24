#ifndef HEADER_WRAPPER
#define HEADER_WRAPPER
#include "library_a/LibraryA.hpp"
#include "library_b/LibraryB.hpp"
#include "rclcpp/rclcpp.hpp"
#include "visualizer/Visualizer.hpp"

class Wrapper : public rclcpp::Node {
 private:
  library_a::LibraryA library_a_;
  library_b::LibraryB library_b_;
  visualizer::Visualizer visualizer_;

 public:
  Wrapper();
};

#endif /* HEADER_WRAPPER */
