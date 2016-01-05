/// @file
/// 
/// コピー、代入の禁止のサンプル
/// 
/// 1. 基本(直接記述)
/// 2. マクロ
/// 3. 継承 (boost::noncopyable)
/// 4. c++11
/// 5. c++11 マクロ
///
/// 
/// コンパイル:
///   (1, 2) g++ protcopy_sample.cpp
///   (3)    g++ -I(boost ヘッダーのパス) protcopy_sample.cpp
///   (4, 5) g++ --std=c++11 protcopy_sample.cpp
/// 

#include <string>
#include <iostream>
#include <string.h>

// 継承 (3)
// #include <boost/utility.hpp>


// コピー禁止 マクロ (2)
// #define NON_COPYABLE(C)       C(const C &);       \
//                               void operator=(const C &)

// コピー禁止 c++11 マクロ (5)
// #define NON_COPYABLE(C)         C& operator=(const C&) = delete;        \
//                                 C(const C&) = delete;

/// 人クラス
class Person
// 継承 (3)
// class Person : boost::noncopyable
{
  char *m_name;                         ///< 名前
  unsigned int m_age;                   ///< 年齢

  
 private:

  // コピー禁止 (1)
  Person(const Person &);
  void operator=(const Person &);

  // コピー禁止(マクロ版) (2, 4)
  // NON_COPYABLE(Person);

  // コピー禁止 (C++11) (5)
  // public:
  //  Person(const Person) = delete;
  //  Person &operator=(const Person &) = delete;
  
 public:
  /// コンストラクター
  Person(const char *name = 0, unsigned int age = 0)
      :m_name(0), m_age(age)
  {
    SetName(name);
  }

  /// デストラクター.
  /// 継承用に仮想化
  virtual ~Person()
  {
    SetName(0);
  }

  ////////////////
  
  // Getter
  const char *GetName() const { return m_name; }
  unsigned int GetAge() const { return m_age; }
  
  // Setter
  Person &SetName(const char *name)
  {
    if (m_name)
    {
      delete m_name;
      m_name = 0;
    }
    if (name) {
      int leng = strlen(name);
      m_name = new char [leng + 1];
      strcpy(m_name, name);
    }
    return *this;
  }
  Person &SetAge(unsigned int age)
  {
    m_age = age;
    return *this;
  }
  
};


  

using namespace std;

int main(void)
{
  Person peter("Peter", 21);

  // コピーコンストラクター
  // Person michael(peter);

  // 代入
  Person tom;
  // tom = peter;
  
  return 0;
}
