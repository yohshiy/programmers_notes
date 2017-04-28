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




//// 左辺値、右辺値で処理を変えるサンプル
////////////////////////////////////////////////////////////////


class Bar
{
  Foo m_foo;    

 public:
  void Set(const Foo &obj)
  {
    std::cout << "Bar::Set(left )" << std::endl;
    m_foo = obj;
  }

  void Set(Foo &&obj)
  {
    std::cout << "Bar::Set(right)" << std::endl;
    m_foo = std::move(obj);
  }

};


//// 完全転送

template <typename T>
void SetBar(Bar &bar, T && val)
{
  bar.Set(val);
}

template <typename T>
void TransSetBar(Bar &bar, T && val)
{
  bar.Set(std::forward<T>(val));
}


////////////////////////////////////////////////////////////////


using namespace std;

int main(void)
{
  //// 標準ライブラリーでの活用
  ////////////////////////////////////////////////////////////////
    
  vector<Foo> foos;
  foos.reserve(4);
    
  Foo left(1);
  foos.push_back(left);
  foos.push_back(Foo(2));

  cout << endl;

  cout << "move vector" << endl;
  vector<Foo> foos2 = std::move(foos);
  
  cout << endl;
  
  
  string str = string("Hello") + " " + "world" + "!";
  cout << str << endl;


  cout << endl << endl;

    
    
  //// 左辺値、右辺値で処理を変えるサンプル
  ////////////////////////////////////////////////////////////////

  Bar bar;
    
  Foo obj(1);    
  bar.Set(obj);
  bar.Set(Foo(5));
  bar.Set(9);

  cout << endl;

  SetBar(bar, obj);
  SetBar(bar, Foo(5));
  SetBar(bar, 9);

  cout << endl;

  TransSetBar(bar, obj);
  TransSetBar(bar, Foo(5));
  TransSetBar(bar, 9);

  cout << endl << endl;

    
  //// 所有権の移動
  ////////////////////////////////////////////////////////////////
    
  std::unique_ptr<string> ptr(new string("Hello"));
  cout << *ptr << endl;
    
  auto newptr = std::move(ptr);
  cout << ((ptr == nullptr) ? "(null)" : *ptr) << endl;
  cout << *newptr << endl;
    
  return 0;
}
