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

/// コピー禁止クラス
class NonCopy
{    
  int m_val;

 public:
  NonCopy(const NonCopy &) = delete;
  void operator=(const NonCopy &) = delete;

  NonCopy(int val=0) :m_val(val) {}    

  int GetVal() const { return m_val; }  
};


class MoveOnly;
std::ostream &operator<<(std::ostream &os, const MoveOnly &obj);

/// 移動だけ OK クラス
class MoveOnly
{    
  int m_val;

 public:
  MoveOnly(const MoveOnly &) = delete;
  void operator=(const MoveOnly &) = delete;

  MoveOnly(int val=0) :m_val(val)
  {
    std::cout << "Default Constructor val = " << val << std::endl;
  }

  MoveOnly(MoveOnly && other)
      :m_val(other.m_val)
  {
    std::cout << "Move Constructor from " << other << std::endl;
  }

  MoveOnly &operator=(MoveOnly && other)
  {
    std::cout << "Move = from " << other << std::endl;
    if (this != &other) {      
      m_val = other.m_val;
    }
    return *this;
  }

  int GetVal() const { return m_val; }  
};


std::ostream &operator<<(std::ostream &os, const MoveOnly &obj)
{
  return os << "MoveOnly{" << obj.GetVal() << "}";
}



using namespace std;

int main(void)
{
  NonCopy ncpy(1);

  // コンパイルエラー
  // NonCopy ncpy2(ncpy);
  // NonCopy ncpy2(NonCopy(2));
  // NonCopy ncpy2(std::move(ncpy));

  NonCopy ncpy3(3);
  // コンパイルエラー
  // ncpy3 = ncpy;
  // ncpy3 = NonCopy(4);
  // ncpy3 = std::move(ncpy);

  ////////////////////////////////////////////////////////////////

  MoveOnly moly(1);
    
  // MoveOnly moly2(moly);                  // コンパイルエラー
  MoveOnly moly21(MoveOnly(21));            // デフォルトコンストラクター
  MoveOnly moly22(std::move(MoveOnly(22))); // 移動コンストラクター

  MoveOnly moly3(3);
  moly3 = MoveOnly(4);
  moly3 = std::move(moly);
    
  return 0;
}
