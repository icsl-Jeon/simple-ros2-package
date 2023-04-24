#include "LibraryA.hpp"
using namespace library_a;

ClassA::ClassA(double variable) : internal_variable_(variable){};
double ClassA::GetVariable() { return internal_variable_; }