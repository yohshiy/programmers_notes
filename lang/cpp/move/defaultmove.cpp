/// @file
/// 
/// 移動、右辺値利用のサンプル
///
/// コンパイル:
///   g++ -std=c++14 movetest.cpp


#include <cstring>

#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <memory>


//// 移動用確認クラス
////////////////////////////////////////////////////////////////

class Foo;
std::ostream &operator<<(std::ostream &os, const Foo &obj);


/// 移動用確認クラス
class Foo
{
  int m_val;

 public:
  Foo(int val=0) :m_val(val) {}

  Foo(const Foo &other)
      :m_val(other.m_val)
  {
    std::cout << "Copy Constructor from " << other << std::endl;
  }

  Foo(Foo && other)
      :m_val(other.m_val)
  {
    std::cout << "Move Constructor from " << other << std::endl;
  }


  Foo &operator=(const Foo &other)
  {
    std::cout << "Copy = from " << other << std::endl;
    if (this != &other) {      
      m_val = other.m_val;
    }
    return *this;
  }

  Foo &operator=(Foo && other)
  {
    std::cout << "Move = from " << other << std::endl;
    if (this != &other) {      
      m_val = other.m_val;
    }
    return *this;
  }
    

  int GetVal() const { return m_val; }
  
  
};

std::ostream &operator<<(std::ostream &os, const Foo &obj)
{
  return os << "Foo{" << obj.GetVal() << "}";
}



/// 自動で移動定義されないクラス
class Bar
{
  Foo m_foo;    ///< 移動対応済みメンバー    

 public:
  Bar(int val=0) :m_foo(val) {}
  ~Bar() {}
};


/// default の移動定義を加えたクラス
class Baz
{
  Foo m_foo;    ///< 移動対応済みメンバー

 public:
  Baz(int val=0) :m_foo(val) {}
  ~Baz() {}  // ← これがあるので移動は自動定義されない

  // コピー定義
  Baz(const Baz &src) = default;
  Baz &operator=(const Baz &src) = default;
  // 移動定義
  Baz(Baz &&src) = default;
  Baz &operator=(Baz &&src) = default;  
};




using namespace std;

int main(void)
{
  Bar bar1(1);
    
  Bar bar2(std::move(bar1));
  cout << endl;

  Bar bar3;
  bar3 = std::move(bar1);

  cout << endl;
  cout << endl;

  Baz baz1(1);
    
  Baz baz2(std::move(baz1));
  cout << endl;

  Baz baz3;
  baz3 = std::move(baz1);

  
  return 0;
}
