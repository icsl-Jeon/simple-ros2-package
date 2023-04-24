#ifndef HEADER_LIBRARYA
#define HEADER_LIBRARYA

namespace library_a {
class ClassA {
private:
  double internal_variable_{0.0};

public:
  ClassA(){};
  ClassA(double variable);
  double GetVariable();
};
} // namespace library_a

#endif /* HEADER_LIBRARYA */
