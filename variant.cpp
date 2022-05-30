

#include <variant>
#include <iostream>

int main() {

  // an union-like type
  std::variant<int, double> x, y;
  x = 1;
  y = 2.0;

  // show the internal index to the real type.
  std::cout << x.index() << "\n";
  std::cout << y.index() << "\n";

  // read the numberr
  std::cout << std::get<int>(x) << "\n";
  std::cout << std::get<double>(y) << "\n";

  // std::get will throw an exception if the type doesn't match.
  // get_if accepts a pointer-to variant
  if (!std::get_if<int>(&y))
    std::cout << "Type mismatches.\n";

  // cooperate with std::visitor







  return 0;
}
