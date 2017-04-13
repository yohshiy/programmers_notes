/// @file
/// 
/// 移動コンストラクター、移動代入演算子のサンプル
///
/// コンパイル:
///   g++ -std=c++14 movableclass_auto.cpp



#include <string>
#include <iostream>
#include <string.h>




/// 人クラス
class Person
{
  std::string m_name;
  unsigned int m_age;

 public:
  /// コンストラクター
  Person(const std::string &name = std::string(), unsigned int age = 0)
      :m_name(name), m_age(age)
  {}

  
  // Getter
  const std::string &GetName() const { return m_name; }
  unsigned int GetAge() const { return m_age; }
  
  // Setter
  Person &SetName(const std::string  &name)
  {
    m_name = name;
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
  return os << "{\"" << person.GetName()
            << "\"(" << person.GetAge() << ")}";
}



  

using namespace std;

int main(void)
{
  Person peter(std::move(Person("Peter", 21)));
  cout << peter << endl;  // {"Peter"(21)}

  Person michael;
  michael = std::move(Person("Michael", 16));
  cout << michael << endl;  // {"Michael"(16)}
  
  return 0;
}
