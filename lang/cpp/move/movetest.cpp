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




//// 引数が左辺値、右辺値かどうかで処理を変える関数
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



//// Sender が左辺値、右辺値かどうかで処理を変えるメソッド
////////////////////////////////////////////////////////////////

class Baz
{
 public:
  // 非 const な左辺値用
  void Method() &
  { 
    std::cout << "Left-value sender" << std::endl;
  }

  // const な左辺値用
  void Method() const &
  { 
    std::cout << "Left-value(const) sender" << std::endl;
  }

  // 右辺値用
  void Method() &&
  { 
    std::cout << "Right-value sender" << std::endl;
  }
};



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

    
    
  //// 左辺値、右辺値で処理を変える関数
  ////////////////////////////////////////////////////////////////

  Bar bar;
    
  Foo obj(1);    
  bar.Set(obj);
  bar.Set(Foo(5));
  bar.Set(9);  // 暗黙的な型変換が起こり Foo(9) が作成される

  cout << endl;

  //// グローバル参照
  
  SetBar(bar, obj);
  SetBar(bar, Foo(5));
  SetBar(bar, 9);

  cout << endl;

  //// 完全転送
  
  TransSetBar(bar, obj);
  TransSetBar(bar, Foo(5));
  TransSetBar(bar, 9);

  cout << endl << endl;



  //// Sender が左辺値、右辺値かどうかで処理を変えるメンバー関数
  ////////////////////////////////////////////////////////////////

  Baz vobj;
  const Baz cobj;

  vobj.Method();
  cobj.Method();
  Baz().Method();

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
