


/// 点
template <typename T = int>
struct Point
{
  T x;
  T y;

  Point(T ax, T ay) :x(ax), y(ay) {}
  Point() : Point(0,0) {}
  
  bool operator==(const Point<T> &rhs) const
  {
    return (x == rhs.x) && (y == rhs.y);
  }
  
};






/// 重み付き点.
/// 点を継承したクラス
template <typename T = int, typename U = int>
struct WeightedPoint : public Point<T>
{
  U weight;

  WeightedPoint(T ax, T ay, U aweitht)
      : Point<T>(ax, ay), weight(aweitht) {}
  
  bool operator==(const WeightedPoint<T> &rhs) const
  {
    return Point<T>::operator==(rhs) && (weight == rhs.weight);
  }
  
};





#include <iostream>

using namespace std;

int main()
{
  cout << boolalpha;
  WeightedPoint<int> wa(1, 1, 10), wb(1, 1, 20);

  cout << "wa == wb : " << (wa == wb) << endl;
}

