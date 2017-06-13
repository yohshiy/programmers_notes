
#include <iostream>
#include <vector>

template <typename T>
class Point
{
    T x_;
    T y_;

  public:
    Point(T x, T y) :x_(x), y_(y) {}
    Point() :Point(T(),T()) {}

    T GetX() const {return x_;}
    T GetY() const {return y_;}
};


template <typename T>
std::ostream &operator<<(std::ostream &out, const Point<T> &pos)
{
    out << "(" << pos.GetX() << ", " << pos.GetY() << ")";
    return out;
}


////////////////////////////////////////////////////////////////


template <typename T>
class Polygon
{
    std::vector< Point<T> > points_;

  public:
    using value_type = T;
    using size_type = typename std::vector< Point<T> >::size_type;
    using iterator = typename std::vector< Point<T> >::iterator;
    using const_iterator = typename std::vector< Point<T> >::const_iterator;

    size_type size() const { return points_.size(); }
    
    iterator begin() { return points_.begin(); }
    iterator end()   { return points_.end(); }
    const_iterator begin() const { return points_.begin(); }
    const_iterator end()   const { return points_.end(); }

    
    void push_back(const Point<T> &pos) { points_.push_back(pos); }
    Point<T> &operator[](size_type idx) {return points_[idx]; }
    const Point<T> &operator[](size_type idx) const {return points_[idx]; }
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Polygon<T> &poly)
{
    out << "Polygon[ ";
    for (const auto &pos : poly) {
        out << pos;
        out << " ";
    }
    out << "]";
    return out;
}




////////////////////////////////////////////////////////////////

int main()
{
    Point<int> pos(1, 2);
    std::cout << pos << std::endl;

    Polygon<int> poly;
    poly.push_back(Point<int>(1, 2));
    poly.push_back(Point<int>(3, 4));
    std::cout << poly << std::endl;

    for (auto cnt = 0U ; cnt < poly.size() ; cnt++)
    {
        std::cout << poly[cnt] << std::endl;
    }
        
    
    return 0;
}

