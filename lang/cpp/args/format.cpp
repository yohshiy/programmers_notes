
#include <iostream>
#include <boost/format.hpp>

int main()
{
  boost::format fmt("Hello %s, %02d, %.3f");
  fmt = fmt % "world" % 3 % 1.2;
  std::cout << fmt << std::endl;  // Hello world, 03, 1.200
}

