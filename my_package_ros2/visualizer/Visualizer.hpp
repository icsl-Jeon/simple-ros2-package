#ifndef HEADER_VISUALIZER
#define HEADER_VISUALIZER

#include "library_a/LibraryA.hpp"
#include "library_b/LibraryB.hpp"
#include "rclcpp/rclcpp.hpp"

namespace visualizer {
class Visualizer : rclcpp::Node {
private:
  library_a::ClassA class_a;
  library_b::ClassB class_b;

public:
  Visualizer();
};
} // namespace visualizer

#endif /* HEADER_VISUALIZER */
