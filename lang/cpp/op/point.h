

/// 点
template <typename T>
struct Point
{
  T x;                                  ///< x 座標
  T y;                                  ///< y 座標

  
  /// メンバー指定のコンストラクター
  Point(T ax, T ay) :x(ax), y(ay) {}

  /// デフォルトコンストラクター
  Point() : Point(0,0) {}
  

  /// 値の設定
  inline Point<T> &Set(T ax, T ay)
  {
    x = ax;
    y = ay;
    return *this;
  }
  
  /// ダンプ
  inline virtual void Dump(::std::ostream& os) const
  {
    os << "(" << x << "," << y << ")";
  }

  
  //// 演算子のオーバーロード

  // 一致
  inline bool operator==(const Point& rhs) const { return ((x == rhs.x) && (y == rhs.y)); }
  inline bool operator!=(const Point& rhs) const { return !(operator==(rhs)); }

  // 加減 - 点と点、点とスカラー
  inline Point &operator+=(const Point &rhs) { return Set(x+rhs.x, y+rhs.y); }
  inline Point &operator+=(T rhs) { return Set(x+rhs, y+rhs); }
  inline Point operator-() const { return Point(-x, -y); }
  inline Point &operator-=(const Point &rhs) { return Set(x-rhs.x, y-rhs.y); }
  inline Point &operator-=(T rhs) { return Set(x-rhs, y-rhs); }

  // 乗除 - 点とスカラー  (点と点は紛らわしいので定義しない)
  inline Point &operator*=(T rhs) { return Set(x*rhs, y*rhs); }
  inline Point &operator/=(T rhs) { return Set(x/rhs, y/rhs); }
  inline Point &operator%=(T rhs) { return Set(x%rhs, y%rhs); }


  /// メンバーの型が異なる点クラスへの型変換演算子.
  ///   明示的に書けば変換できるようにするために定義
  ///
  ///     Point<double> rpos = {1.5, 2.3};
  ///     Point<int> ipos1 = static_cast<Point<int> >(rpos);  // OK {1, 2} (切り捨て)
  ///     Point<int> ipos2(rpos);                             // OK
  ///     Point<int> ipos3 = rpos;                            // NG 暗黙的な変換は禁止
  ///     Point<int> ipos4 = Point<int>(1,2);                 // OK 同一型はコピーコンストラクター
  ///
  template <typename U>
  explicit inline operator Point<U>() const
  {
    return Point<U>(static_cast<U>(x), static_cast<U>(y));
  }

};

//// 点クラスとの演算子のオーバーロード(二項)

// 加減 - 点と点、点とスカラー
template <typename T, typename U>
inline auto operator+(const Point<T> &a, const Point<U> &b) -> Point<decltype(a.x+b.x)> { return {a.x+b.x, a.y+b.y}; }
template <typename T, typename U>
inline auto operator+(const Point<T> &a, U b) -> Point<decltype(a.x+b)> { return {a.x+b, a.y+b}; }
template <typename T, typename U>
inline auto operator+(T a, const Point<U> &b) -> Point<decltype(a+b.x)> { return {a+b.x, a+b.y}; }
template <typename T, typename U>
inline auto operator-(const Point<T> &a, const Point<U> &b) -> Point<decltype(a.x-b.x)> { return {a.x-b.x, a.y-b.y}; }
template <typename T, typename U>
inline auto operator-(const Point<T> &a, U b) -> Point<decltype(a.x-b)> { return {a.x-b, a.y-b}; }
template <typename T, typename U>
inline auto operator-(T a, const Point<U> &b) -> Point<decltype(a-b.x)> { return {a-b.x, a-b.y}; }

// 剰余 - 点とスカラー
template <typename T, typename U>
inline auto operator*(const Point<T> &a, U b) -> Point<decltype(a.x*b)> { return {a.x*b, a.y*b}; }
template <typename T, typename U>
inline auto operator*(T a, const Point<U> &b) -> Point<decltype(a*b.x)> { return {a*b.x, a*b.y}; }
template <typename T, typename U>
inline auto operator/(const Point<T> &a, U b) -> Point<decltype(a.x/b)> { return {a.x/b, a.y/b}; }
template <typename T, typename U>
inline auto operator/(T a, const Point<U> &b) -> Point<decltype(a/b.x)> { return {a/b.x, a/b.y}; }
template <typename T, typename U>
inline auto operator%(const Point<T> &a, U b) -> Point<decltype(a.x%b)> { return {a.x%b, a.y%b}; }
template <typename T, typename U>
inline auto operator%(T a, const Point<U> &b) -> Point<decltype(a%b.x)> { return {a%b.x, a%b.y}; }

/// 点クラスの出力演算子のオーバーロード
template <typename T>
inline ::std::ostream& operator<<(::std::ostream& os, const Point<T>& obj)
{
  obj.Dump(os);
  return os;
}
