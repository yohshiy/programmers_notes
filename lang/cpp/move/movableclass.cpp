/// @file
/// 
/// 移動コンストラクター、移動代入演算子の定義サンプル
///
/// コンパイル:
///   g++ -std=c++14 movableclass.cpp



#include <string>
#include <iostream>
#include <string.h>


/// Person クラスの出力.
/// (宣言を先に書いていないとコンパイルエラー)
class Person;
std::ostream &operator<<(std::ostream &os, const Person &person);


/// 人クラス
class Person
{
  char *m_name;         ///< 名前
  unsigned int m_age;   ///< 年齢

 public:
  /// コンストラクター
  Person(const char *name = nullptr, unsigned int age = 0)
      :m_name(0), m_age(age)
  {
    SetName(name);
  }

  /// デストラクター.
  virtual ~Person()
  {
    SetName(nullptr);
  }

  // コピー
  ////////////////

  /// コピーコンストラクター
  Person(const Person &other)
      :m_age(other.m_age)
  {
    SetName(other.m_name);
  }

  /// 代入演算子
  Person &operator=(const Person &other)
  {
    // 自身の代入チェック
    if (this != &other) {      
      SetName(other.m_name);
      m_age = other.m_age;
    }
    return *this;
  }

  ////////////////

  /// 移動コンストラクター
  Person(Person && other)
      :m_age(other.m_age)
  {
    std::cout << "Move Constructor from " << other << std::endl;
    m_name = other.m_name;
    other.m_name = nullptr;
  }

  /// 移動代入演算子
  Person &operator=(Person && other)
  {
    std::cout << "Move = from " << other << std::endl;
    // 自身の代入チェック
    if (this != &other) {      
      m_name = other.m_name;
      other.m_name = nullptr;  // 元のは NULL を指すように変更
      m_age = other.m_age;
    }
    return *this;
  }
    

  ////////////////
  
  // Getter
  const char *GetName() const { return m_name; }
  unsigned int GetAge() const { return m_age; }
  
  // Setter
  Person &SetName(const char *name)
  {
    // 前の分は解放
    if (m_name != nullptr)
    {
      delete m_name;
      m_name = nullptr;
    }

    // NULL でなければメモリーを確保
    if (name != nullptr) {
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

std::ostream &operator<<(std::ostream &os, const Person &person)
{
  return os << "{\"" << ((person.GetName() != nullptr) ? person.GetName() : "")
            << "\"(" << person.GetAge() << ")}";
}



  

using namespace std;

int main(void)
{
  Person peter(std::move(Person("Peter", 21)));
  Person michael;
  michael = Person("Michael", 16);
  
  return 0;
}
