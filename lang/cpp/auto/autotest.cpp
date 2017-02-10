#include <iostream>

using namespace std;


/// グローバル定数
const auto VERION = "1.0.0";


template <typename T>
struct Point
{
  /// メンバー変数
  T x = 0;
  T y = 0;

  // auto x = 0; NG

  /// クラス変数
  static const auto point_dim = 2;
  // static auto point_dim = 2; NG const のみ OK

  Point(T ax, T ay)
      :x(ax), y(ay) {}

  Point PlusAuto(auto val) const
  {
    return Point(static_cast<T>(x+val), static_cast<T>(y+val));
  }

  template <typename U>
  auto Plus(U val) const
  {
    return Point<decltype(x+val)>(x+val, y+val);
  }

  // auto Plus(auto val) const
  // {
  //   return Point<decltype(x+val)>(x+val, y+val);
  // }

};


template <typename T, typename U>
static auto Add(const Point<T> &a, U b)
{
  return Point<decltype(a.x+b)>(a.x+b, a.y+b);
}


template <typename T, typename U>
static auto OldAdd(const Point<T> &a, U b) -> Point<decltype(a.x+b)>
{
  return {a.x+b, a.y+b};
}


template <typename T, typename U>
auto MyMax(const T &a, const U &b)
{
  if (a < b) {
    return b;
  }
  else {
    return a;
  }
}


template <typename T, typename U>
auto ExtMyMax(const T &a, const U &b) -> decltype(a+b)
{
  return (a < b) ? b : a;
}


    

// static 変数
static auto stvar = 1.0;


int main()
{
  auto localver = 1;

  auto pos = Point<int>(1, 2);
  auto pluspos = pos.Plus(2.5);
  auto pluspos2 = pos.PlusAuto(2.5);
  

  auto added = Add(pos, 0.5);  // Point<double>(1.5, 2.5)

  auto plus = [](auto a, auto b) { return a + b; };
  int result = plus(2, 3); // result = 5

  cout << MyMax(10, 12) << endl;
  cout << ExtMyMax(10.2, 12) << endl;
  
  return localver;
}

