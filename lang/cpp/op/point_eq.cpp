

template <class T>
struct Equalable
{
  virtual bool operator==(const T &rhs) const = 0;
  bool operator!=(const T &rhs) const { return !operator==(rhs); }
};


/// 点
template <typename T>
struct Point : public Equalable<Point<T> >
{
  T x;
  T y;

  Point(T ax, T ay) :x(ax), y(ay) {}
  
  virtual bool operator==(const Point<T> &rhs) const override
  {
    return (x == rhs.x) && (y == rhs.y);
  }
  
};


#include <iostream>

using namespace std;

int main()
{
  cout << boolalpha;
  Point<int> a(1, 2), b(2, 3);

  cout << "a == b : " << (a==b) << endl;
  cout << "a != b : " << (a!=b) << endl;
}

