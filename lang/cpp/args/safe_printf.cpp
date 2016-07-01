
#include <iostream>
#include <boost/format.hpp>



inline void safe_printf(boost::format &bfmt)
{
  std::cout << bfmt;
}
 
template<typename First, typename... Rest>
void safe_printf(boost::format &bfmt, const First& first, const Rest&... rest)
{
  bfmt = bfmt % first;
  safe_printf(bfmt, rest...);
}


template<typename... Rest>
void safe_printf(const char *fmt, const Rest&... rest)
{
  boost::format bfmt(fmt);
  safe_printf(bfmt, rest...);
}


int main()
{
  boost::format fmt("Hello %s, %02d, %.3f\n");
  safe_printf(fmt, "world", 3, 1.2);  // Hello world, 03, 1.200
  safe_printf("Hello %s, %02d, %.3f\n", "world", 3, 1.2);  // Hello world, 03, 1.200
  return 0;
}

