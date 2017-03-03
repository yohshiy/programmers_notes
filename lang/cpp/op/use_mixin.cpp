/// @file
/// ComparableMixIn のサンプル
///
///     $ g++ -std=c++11 -I. use_mixin.cpp
/// 


#include "ComparableMixIn.h"


/// 点
struct Point : public ComparableMixIn<Point>
{
  int x;
  int y;

  Point(int ax, int ay) :x(ax), y(ay) {}

  /// 比較関数.
  /// x で比較し、同じなら y で比較
  virtual int Compare(const Point &other) const override
  {
    return ((x != other.x) ? (x - other.x) : (y - other.y));
  }
  
};


#include <iostream>

using namespace std;

int main()
{
  Point a(1, 2), b(2, 3);

  cout << boolalpha;
  cout << "a == b : " << (a == b) << endl;
  cout << "a != b : " << (a != b) << endl;
  cout << "a <  b : " << (a <  b) << endl;
  cout << "a <= b : " << (a <= b) << endl;
  cout << "a >  b : " << (a >  b) << endl;
  cout << "a >= b : " << (a >= b) << endl;
}

