/// @file
/// auto samples
///
///     $ g++ -std=c++14 autotest.cpp
/// 

#include <iostream>
#include <stdint.h>
#include <typeinfo>


using namespace std;

int foofunc()
{
  // ローカル変数
  auto localver = 1;

  // リテラルの工夫
  auto cstr = "Hellow";  // const char *
  auto str  = "Hellow"s; // std::string
  cout << cstr << endl;
  cout << str  << endl;

  return localver;
}


/// グローバル変数
extern int64_t ErrNo;

// static 変数
static auto stvar = 1.0;

/// グローバル定数
const auto VERION = "1.0.0";




class Foo
{
  /// メンバー変数
  int m_bar = 0;
  // auto m_baz = 0; NG

  /// クラス変数
  static const int Dim = 2;
  // static int Dim = 2; NG const のみ OK
  static constexpr double Mag = 0.5;

  /// クラス変数 (Auto)
  static const auto DimAuto = 2;
  static constexpr auto MagAuto = 0.5;
};



////////////////////////////////////////////////////////////////


template <typename T>
auto StdMax(const T &a, const T &b)
{
  return (a < b) ? b : a;
}

template <typename T, typename U>
auto MyMax(const T &a, const U &b)
{
  return (a < b) ? b : a;
}


template <typename T, typename U>
auto MyMax2Return(const T &a, const U &b)
{
  if (a < b) {
    return b;
  }
  else {
    return a;
  }
}


template <typename T, typename U>
auto FixedMyMax2Return(const T &a, const U &b) -> decltype(a+b)
{
  if (a < b) {
    return b;
  }
  else {
    return a;
  }
}

////////////////////////////////////////////////////////////////

template <typename T>
struct Point
{
  T x;
  T y;

  Point(T ax, T ay)
      :x(ax), y(ay) {}

#if 0
  // コンパイルは通らない
  auto Plus(auto val) const
  {
    return Point(static_cast<T>(x+val), static_cast<T>(y+val));
  }
#endif

  // 引数だけ auto
  Point PlusAutoArg(auto val) const
  {
    return Point(static_cast<T>(x+val), static_cast<T>(y+val));
  }

  // 戻り値だけ auto
  template <typename U>
  auto PlusAutoReturn(U val) const
  {
    return Point<decltype(x+val)>(x+val, y+val);
  }


};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Point<T> &p)
{
  out << "Point(" << p.x << ", " << p.y << ")";
  return out;
}


#if 1

template <typename T, typename U>
inline auto operator*(const Point<T> &a, U b)
{
  return Point<decltype(a.x*b)>(a.x*b, a.y*b);
}

#else

template <typename T, typename U>
inline auto operator*(const Point<T> &a, U b) -> Point<decltype(a.x*b)>
{
  return {a.x*b, a.y*b};
}

#endif



int main()
{      
  cout << StdMax(4, 12) << endl;  // 12

  cout << MyMax(4.2, 12) << endl;  // 12
  cout << MyMax(4.2,  2) << endl;  // 4.2

  cout << MyMax2Return(4, 12) << endl;  // 12
  // cout << MyMax2Return(4.2, 12) << endl;  // コンパイルエラー  
  cout << endl;
  
  cout << FixedMyMax2Return(4.2, 12) << endl;  // 12.0
  cout << FixedMyMax2Return(4.2,  2) << endl;  //  4.2

  cout << endl;

  
  cout << Point<int>(3, 2) * 0.5 << endl;  // Point<double>(1.5, 1.0)

  Point<int> pos(3, 2);
  cout << pos.PlusAutoArg(2.5) << endl;    // Point(5, 4)
  cout << pos.PlusAutoReturn(2.5) << endl; // Point(5.5, 4.5)

  
  auto plus = [](auto a, auto b) { return a + b; };
  cout << plus(2,   3) << endl; // result = 5
  cout << plus(2.5, 3) << endl; // result = 5.5
  
  return 0;
}

