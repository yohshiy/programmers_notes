
#include <string>
#include <iostream>


using namespace std;


extern double Mag;


static auto mag = 1.0;


const double MyPi = 3.14;

const auto MyPiA = 3.14;


class Foo
{
  static const int classval_int = 3;
};

  
class Foo2
{  
  static const auto classval_int = 3;
  static constexpr auto classval_dbl = 3.1;  
};


class Baz
{
  double objval_real = 3.15;
  // auto objval_real_a = 3.15;  // NG  
};


// template <typename T>
// auto MyMax(const T &a, const T &b)
// {
//   return (a < b) ? b : a;
// }

template <typename T, typename U>
auto MyMax(const T &a, const U &b)
{
  return (a < b) ? b : a;
}

template <typename T, typename U>
auto MyMax3(const T &a, const U &b)
{
  if (a < b) {
    return b;
  }
  else {
    return a;
  }
}





int main()
{
  auto num = 5;                // int
  auto cstr = "Hello";         // char *
  auto str = string("Hello");  // string

  const auto cnum = 10;
  auto &ref = str;
  
  auto lstr = "Hello"s;  // string
  

  auto maxval = MyMax(3.1, 5);
  auto maxval2 = MyMax(1, 2.3);
  cout << maxval  << endl;
  cout << maxval2 << endl;
  auto maxval3 = MyMax3(1, 2.3);
  cout << maxval3 << endl;
  
  
  return 0;
}
