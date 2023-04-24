#ifndef HEADER_LIBRARYB
#define HEADER_LIBRARYB

#include "library_a/LibraryA.hpp"
namespace library_b {
class LibraryB {
 private:
  double internal_variable_;
  library_a::LibraryA library_a_;

 public:
  LibraryB(){};
  LibraryB(double variable);
};
}  // namespace library_b

#endif /* HEADER_LIBRARYB */
