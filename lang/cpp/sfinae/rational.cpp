
#include <type_traits>
#include <iostream>

template <typename IntType, typename std::enable_if_t<std::is_integral<IntType>::value, std::nullptr_t> = nullptr>
class Rational
{
  public:
    Rational(IntType num, IntType deno = 1)
            :m_num(num), m_deno(deno)
    {}

    IntType GetNum() const {return m_num;}
    IntType GetDemo() const {return m_deno;}
    
  private:
    IntType m_num;
    IntType m_deno;
};

template <typename IntType>
std::ostream &operator<<(std::ostream &out, const Rational<IntType> &obj)
{
    out << obj.GetNum() << "/" << obj.GetDemo();
    return out;
}




int main()
{
    Rational<int> ra(5, 2);
    // Rational<double> ra(5.2, 2.1); コンパイルエラー

    std::cout << ra << std::endl;
    
    return 0;
}

