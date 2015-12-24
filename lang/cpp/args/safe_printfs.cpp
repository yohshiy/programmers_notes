//
// printf : 可変長引数関数のサンプル
//
// g++ -std=c++11 -I<BoostPath> safe_printfs.cpp

#include <iostream>
#include <boost/format.hpp>



inline void safe_format(boost::format &fmt)
{  
}


template<typename First, typename... Rest>
void safe_format(boost::format &fmt, const First& first, const Rest&... rest)
{
  fmt = fmt % first;
  safe_format(fmt, rest...);
}


// 安全版 sprintf
template<typename... Rest>
std::string safe_sprintf(const char *fmt, const Rest&... rest)
{
  boost::format bfmt(fmt);
  safe_format(bfmt, rest...);
  return boost::str(bfmt);
}


// 安全版 fprintf
template<typename... Rest>
void safe_fprintf(std::ostream &out, const char *fmt, const Rest&... rest)
{
  boost::format bfmt(fmt);
  safe_format(bfmt, rest...);
  out << bfmt;
}


// 安全版 printf
template<typename... Rest>
void safe_printf(const char *fmt, const Rest&... rest)
{
  safe_fprintf(std::cout, fmt, rest...);
}



int main()
{
  const char *fmt = "Hello %s, %02d, %.3f\n";
  
  std::cout << safe_sprintf(fmt, "world", 3, 1.2);
  safe_fprintf(std::cout, fmt, "world", 3, 1.2);
  safe_printf(fmt, "world", 3, 1.2);
  
  return 0;
}

