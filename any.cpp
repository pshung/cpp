
#include <any>
#include <ios>
#include <iostream>

using std::any;
using std::cout;
using std::any_cast;

int main() {

  std::boolalpha(cout);
  // any type can contain any type.
  any a = 1;
  cout << a.type().name() << "\n";
  cout << any_cast<int>(a) << "\n";

  a = 3.14;
  cout << a.type().name() << "\n";
  cout << any_cast<double>(a) << "\n";

  a = true;
  cout << a.type().name() << "\n";
  cout << any_cast<bool>(a) << "\n";

  // has_value to check the contained value
  any b;
  if (!b.has_value()) 
    cout << "B hasn't a value.\n";

  b = 1;
  if (b.has_value()) 
    cout << "B has a value.\n";

  // reset, clear the contained value
  b.reset();
  if (!b.has_value()) 
    cout << "B hasn't a value.\n";

  // swap, exchange the contained value
  b = 1;
  b.swap(a);
  cout << a.type().name() << "\n";
  cout << any_cast<int>(a) << "\n";

  cout << b.type().name() << "\n";
  cout << any_cast<bool>(b) << "\n";

  // obtain a pointer pointing to the contained value.
  int* a_p  = any_cast<int>(&a);
  cout << *a_p << "\n";

  class MyData {
  public:
    int m;
    bool b;
    MyData(int mm, bool bb): m(mm), b(bb) {}
  };

  // emplace, change the contained value with the constructor in place.
  a.emplace<MyData>(1, true);
  cout << a.type().name() << "\n";
  cout << any_cast<MyData>(a).m << "\n";
  cout << any_cast<MyData>(a).b << "\n";




  return 0;
}
