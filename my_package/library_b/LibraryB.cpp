#include "LibraryB.hpp"
using namespace library_b;

ClassB::ClassB(double variable)
    : internal_variable_(variable), library_a_(variable + 1) {}

double ClassB::GetVariable() { return internal_variable_ + 3; };