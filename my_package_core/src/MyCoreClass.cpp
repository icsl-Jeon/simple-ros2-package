#include "my_package_core/MyCoreClass.hpp"

MyCoreClass::MyCoreClass(int int_var) : int_var_(int_var) {}

double MyCoreClass::GetVaraible() const { return int_var_; }
