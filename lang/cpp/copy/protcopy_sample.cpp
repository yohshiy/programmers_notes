
#include <string>
#include <iostream>
#include <string.h>

////////////////////////////////////////////////////////////////
//// コピー禁止のサンプル
////////////////////////////////////////////////////////////////

// #define NON_COPYABLE(C)       C(const C &);       \
//                               void operator=(const C &)

// #include <boost/utility.hpp>

// #define NON_COPYABLE(C)         C& operator=(const C&) = delete;        \
//                                 C(const C&) = delete;

/// 人クラス
class Person
// class Person : boost::noncopyable
{
  char *m_name;                         ///< 名前
  unsigned int m_age;                   ///< 年齢

  
 private:

  // コピー禁止
  Person(const Person &);
  void operator=(const Person &);

  // コピー禁止(マクロ版)
  // NON_COPYABLE(Person);

  // コピー禁止 (C++11)
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
