﻿
#include <string>
#include <iostream>


class Person
{
  std::string m_name;
  int m_age;

public:
  Person() :m_age(0) {}
  
  // Getter
  const std::string &name() const { return m_name; }
  int age() const { return m_age; }
  
  // Setter
  Person &name(const std::string &name)
  {
    m_name = name;
    return *this;
  }
  Person &age(int age)
  {
    m_age = age;
    return *this;
  }
  
};

inline std::ostream &operator<<(std::ostream &os, const Person &person)
{
  return os << "{\"" << person.name() << "\"(" << person.age() << ")}";
}


using namespace std;

int main(void)
{
  Person person;
  cout << person.name("Peter").age(21) << endl;  // {"Peter"(21)}

  return 0;
}
