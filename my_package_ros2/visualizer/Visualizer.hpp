#ifndef HEADER_VISUALIZER
#define HEADER_VISUALIZER

#include "library_a/LibraryA.hpp"
#include "library_b/LibraryB.hpp"
#include "rclcpp/rclcpp.hpp"

namespace visualizer {
class Visualizer : rclcpp::Node {
 private:
  library_a::LibraryA library_a_;
  library_b::LibraryB library_b_;

 public:
  Visualizer();
};
}  // namespace visualizer

#endif /* HEADER_VISUALIZER */
