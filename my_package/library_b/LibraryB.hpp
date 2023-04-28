#ifndef HEADER_LIBRARYB
#define HEADER_LIBRARYB

#include "library_a/LibraryA.hpp"
namespace library_b {
class ClassB {
private:
  double internal_variable_{1.0};
  library_a::ClassA library_a_;

public:
  ClassB(){};
  ClassB(double variable);
  double GetVariable();
};
} // namespace library_b

#endif /* HEADER_LIBRARYB */
