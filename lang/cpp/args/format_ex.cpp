
#include <iostream>
#include <exception>
#include <boost/format.hpp>

int main()
{
  boost::format fmt("Hello %s, %02d, %.3f");
  try
  {
    fmt = fmt % 1 % "world" % 1.2 % 1;
    std::cout << fmt << std::endl;
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }
}

