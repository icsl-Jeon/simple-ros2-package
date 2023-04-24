#include "LibraryB.hpp"
using namespace library_b;

LibraryB::LibraryB(double variable)
    : internal_variable_(variable), library_a_(variable + 1){};