/// @file
/// 
/// コピーコンストラクター、代入演算子のサンプル
///
/// コンパイル:
///   g++ copy_sample.cpp



#include <string>
#include <iostream>
#include <string.h>


/// 人クラス
class Person
{
  char *m_name;                         ///< 名前
  unsigned int m_age;                   ///< 年齢

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

  /// コピーコンストラクター
  Person(const Person &other)
      :m_age(other.m_age)
  {
    SetName(other.m_name);
  }

  Person &operator=(const Person &other)
  {
    // 自身の代入チェック
    if (this == &other) {      
      SetName(other.m_name);
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

inline std::ostream &operator<<(std::ostream &os, const Person &person)
{
  return os << "{\"" << person.GetName() << "\"(" << person.GetAge() << ")}";
}



////////////////////////////////////////////////////////////////
//// コピーコンストラクター、代入演算子の継承サンプル
////////////////////////////////////////////////////////////////

/// 学生クラス
class Student : public Person
{
  char *m_school;                         ///< 学校名

public:
  /// コンストラクター
  Student(const char *name = 0, unsigned int age = 0, const char *school = 0)
      :Person(name, age)
  {
    SetSchool(school);
  }

  /// デストラクター.
  /// 継承用に仮想化
  virtual ~Student()
  {
    SetSchool(0);
  }

  ////////////////////////////////////////////////////////////////

  /// コピーコンストラクター
  Student(const Student &other)
      :Person(other)
  {
    SetSchool(other.m_school);
  }

  Student &operator=(const Student &other)
  {
    // 自身の代入チェック
    if (this == &other) {
      // 基底クラスメンバーの代入
      Person::operator=(other);
      SetSchool(other.m_school);
    }
    return *this;
  }

  ////////////////////////////////////////////////////////////////
  
  // Getter
  const char *GetSchool() const { return m_school; }
  
  // Setter
  Student &SetSchool(const char *school)
  {
    if (m_school)
    {
      delete m_school;
      m_school = 0;
    }
    if (school) {
      int leng = strlen(school);
      m_school = new char [leng + 1];
      strcpy(m_school, school);
    }
    return *this;
  }
};

inline std::ostream &operator<<(std::ostream &os, const Student &student)
{
  const Person &person = student;
  return os << person << "-\"" << student.GetSchool() << "\"";
}

  

using namespace std;

int main(void)
{
  Student peter("Peter", 21, "Foo University");
  cout << peter << endl;  // {"Peter"(21)}-"Foo University"

  Student michael(peter), tom;
  michael.SetName("Michael");
  cout << michael << endl;  // {"Michael"(21)}-"Foo University"

  tom = michael;
  tom.SetName("Tom");
  cout << michael << endl;  // {"Michael"(21)}-"Foo University"
  
  return 0;
}
