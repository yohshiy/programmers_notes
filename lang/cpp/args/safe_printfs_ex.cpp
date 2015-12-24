
#include <iostream>
#include <boost/format.hpp>
#include <stdlib.h>
#include <exception>


inline boost::format safe_format(boost::format &fmt)
{
}
 
template<typename First, typename... Rest>
void safe_format(boost::format &fmt, const First& first, const Rest&... rest)
{
  fmt = fmt % first;  
}


template<typename First, typename... Rest>
std::string safe_sprintf(const char *fmt, const First& first, const Rest&... rest)
{
  try
  {
    boost::format bfmt(fmt);
    safe_format(bfmt, first, rest...);
    std::cout << bfmt << std::endl;
    return "";
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
    exit(EXIT_FAILURE);
  }
}



int main()
{
  std::cout << safe_sprintf("Hello %s, %02d, %.3f\n", "world", 3, 1.2);
  return 0;
}

