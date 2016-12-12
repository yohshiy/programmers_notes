///
/// C++14 Streams サンプル
///
/// g++ -std=c++14 -I "Stream.h のあるパス" sample.cpp


#include <iostream>
#include <string>
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}


#include "Stream.h"

using namespace stream;
using namespace stream::op;

#include <sstream>



template <typename T>
void Dump(T &seq)
{
  seq | print_to(std::cout);
  std::cout << std::endl;
}



int main()
{
  MakeStream::from({1, 3, 8, 4, 7})
      | map_([](auto x) { return x * 2; })
      | print_to(std::cout);
  
  std::cout << std::endl;

  auto seq = MakeStream::from({1, 3, 8, 4, 7})
             | map_([](auto x) { return x * x; });
  Dump(seq);
  
  auto str = MakeStream::from({1, 3, 8, 4, 7})
             | map_([](auto x) { return patch::to_string(x); })
             | reduce([](auto result, auto elem) { return result + "," + elem; });
  std::cout << str << std::endl;
  
  return 0;
}
