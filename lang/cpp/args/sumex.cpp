//
// sum の改良版
//
// g++ -std=c++11 -I<BoostPath> safe_printfs.cpp


#include <iostream>
#include <boost/lexical_cast.hpp>


template<typename Ret>
Ret any_sumex()
{
  return Ret();
}
 
template<typename Ret, typename First, typename... Rest>
Ret any_sumex(const First& first, const Rest&... rest)
{
  return boost::lexical_cast<Ret>(first) + any_sumex<Ret>(rest...);
}


////////////////////////////////////////////////////////////////
//// 使用例
////////////////////////////////////////////////////////////////

using namespace std;

int main()
{
  cout << any_sumex<int>(1.0, 2.2, 3.3, 4.9) << endl;    // 10
  cout << any_sumex<double>(1.0, 2, 3.3, 4.9) << endl;   // 11.2
  cout << any_sumex<string>("Hello", " ", "world", "!") << endl;  // "Hello world!"
  cout << any_sumex<string>("Hello ", "world ", 3, " ", 1.2) << endl;  // "Hello world 3 1.2"
  
  return 0;
}

