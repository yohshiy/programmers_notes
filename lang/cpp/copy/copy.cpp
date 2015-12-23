
#include "iostream"


class Person
{
private:
	std::string m_name;
	int m_age;
	// :
};

class HaveCopy
{
 public:
  HaveCopy()
      :value_(0)
  {
    std::cout << "HaveCopy : Default constractor" << std::endl;
  }

  HaveCopy(const HaveCopy &other)
      :value_(other.value_)
  {
    std::cout << "HaveCopy : Copy constractor" << std::endl;
  }

  HaveCopy &operator=(const HaveCopy &other)
  {
    std::cout << "HaveCopy : Assignment operator" << std::endl;
    if (&other != this)
    {
      value_ = other.value_;
    }
    return *this;
  }

 private:
  int value_;
};

  
class Bar
{
 public:
  Bar() {}
  virtual ~Bar() {}

 private:
  HaveCopy member_;
};


class Baz : public Bar
{
 public:
  Baz() {}
  virtual ~Baz() {}
};


int main()
{  
  Baz a;     // HaveCopy : Default constractor
  Baz b(a);  // HaveCopy : Copy constractor

  Baz c;     // HaveCopy : Default constractor
  c = b;     // HaveCopy : Assignment operator
  
  Baz d = a; // HaveCopy : Copy constractor

  Foo a;
  Foo b(a);  // コピーコンスタクター

  Foo a, c;
  c = a;     // 代入演算子

  Foo a;
  Foo d = a; // コピーコンスタクター

  return 0;
}

