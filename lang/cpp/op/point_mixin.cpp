

template <class T>
struct Comparable
{
  virtual int Compare(const T &rhs) const = 0;
  bool operator==(const T &rhs) const { return Compare(rhs) == 0; };
  bool operator!=(const T &rhs) const { return Compare(rhs) != 0; };
  bool operator< (const T &rhs) const { return Compare(rhs) <  0; };
  bool operator<=(const T &rhs) const { return Compare(rhs) <= 0; };
  bool operator> (const T &rhs) const { return Compare(rhs) >  0; };
  bool operator>=(const T &rhs) const { return Compare(rhs) >= 0; };
};


/// 点
template <typename T>
struct Point : public Comparable<Point<T> >
{
  T x;                                  ///< x 座標
  T y;                                  ///< y 座標

  Point(T ax, T ay) :x(ax), y(ay) {}

  /// 比較関数.
  /// x で比較し、同じなら y で比較
  virtual int Compare(const Point<T> &rhs) const override
  {
    return static_cast<int>((x == rhs.x) ? (y - rhs.y) : (x - rhs.x));
  }
  
};


#include <iostream>

using namespace std;

int main()
{
  cout << boolalpha;
  Point<int> a(1, 2), b(2, 3);

  cout << "a == b : " << (a == b) << endl;
  cout << "a != b : " << (a != b) << endl;
  cout << "a <  b : " << (a <  b) << endl;
  cout << "a <= b : " << (a <= b) << endl;
  cout << "a >  b : " << (a >  b) << endl;
  cout << "a >= b : " << (a >= b) << endl;
}

