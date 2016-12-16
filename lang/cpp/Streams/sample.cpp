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
void DumpStream(T &seq)
{
  seq | print_to(std::cout);
  std::cout << std::endl;
}

template <typename T>
void Dump(const T &val)
{
  std::cout << val << std::endl;
}



int main()
{
  MakeStream::from({1, 3, 8, 4, 7})
      | map_([](auto x) { return x * 2; })
      | print_to(std::cout);
  
  std::cout << std::endl;

  auto seq = MakeStream::from({1, 3, 8, 4, 7})
             | map_([](auto x) { return x * x; });
  DumpStream(seq);
  
  auto str = MakeStream::from({1, 3, 8, 4, 7})
             | map_([](auto x) { return patch::to_string(x); })
             | reduce([](auto result, auto elem) { return result + "," + elem; });
  Dump(str);


  // map 
  auto mapseq =
      MakeStream::from({3, 2, 9, 6})
      | map_([](auto elem) { return elem * 2; });  // 6 4 18 12 
  DumpStream(mapseq);  


  // filter 
  auto filterseq =
      MakeStream::from({3, 2, 9, 6})
      | filter([](auto elem) { return elem % 2 == 1; });  // 3 9 
  DumpStream(filterseq);  


  std::vector<int> src = {3, 2, 9, 6};
  Dump(MakeStream::from(src) | reduce([](auto sum, auto elem) { return sum + elem; })); // 20
  Dump(MakeStream::from(src) | reduce([](auto max, auto elem) { return (max < elem) ? elem : max; })); // 9
  Dump(MakeStream::from(src) | identity_reduce(0, [](auto count, auto elem) { return count + 1; })); // 4

  // {3, 2, 9, 6}
  // (3, 2) => 3 + 2
  //                 (5, 9) => 5 + 9
  //                                 (14, 6) => 14 + 6
  //                                                   20

  // count 
  Dump(MakeStream::from({3, 2, 9, 6}) | count());  // 4
  
  // limit
  auto limitseq =
      MakeStream::from({3, 2, 9, 6}) | limit(2);
  DumpStream(limitseq);  // 3 2

  // max 
  Dump(MakeStream::from({3, 2, 9, 6}) | max());  // 9
  // min 
  Dump(MakeStream::from({3, 2, 9, 6}) | min());  // 2

  std::cout << std::boolalpha;
  Dump(MakeStream::from({3, 2, 9, 6}) | all([](auto elem) { return (elem % 3) == 0;}));  // false
  Dump(MakeStream::from({3, 2, 9, 6}) | any([](auto elem) { return (elem % 3) == 0;}));  // true

  
  // 四則演算
  auto divseq = MakeStream::from({3, 2, 9, 6}) / 3.0;
  DumpStream(divseq);  // 1 0.666667 3 2 

  auto mulseq = 5 * MakeStream::from({3, 2, 9, 6});
  DumpStream(mulseq);  // 15 10 45 30 

  auto modseq = MakeStream::from({3, 2, 9, 6}) % 3;
  DumpStream(modseq);  // 0 2 0 0 

  auto dot_prod = MakeStream::from({3, 2, 9}) * MakeStream::from({1, 2, 3});
  DumpStream(dot_prod);  // 3 4 27 


  // sort
  auto sortseq =
      MakeStream::from({3, 2, 9, 6}) | sort();
  DumpStream(sortseq);  // 2 3 6 9 

  std::cout << std::endl;
  auto conseq =
      MakeStream::from({3, 2, 9, 6})
      | peek([](auto elem) { std::cout << "[in]  : " << elem << std::endl; })
      | filter([](auto elem) { return elem % 3 == 0; })
      | peek([](auto elem) { std::cout << " - filter : " << elem << std::endl; })
      | map_([](auto elem)  { return elem * 2; })
      | peek([](auto elem) { std::cout << " - map    : " << elem << std::endl; });
  
  for (auto &elem : conseq) {
    std::cout << "[out] : " << elem << std::endl;
  }

  std::cout << std::endl;
  auto conseq2 =
      MakeStream::from({3, 2, 9, 6})
      | peek([](auto elem) { std::cout << "[in]  : " << elem << std::endl; })
      | filter([](auto elem) { return elem % 3 == 0; })
      | peek([](auto elem) { std::cout << " - filter : " << elem << std::endl; })
      | sort()
      | peek([](auto elem) { std::cout << " - sort : " << elem << std::endl; })
      | map_([](auto elem)  { return elem * 2; })
      | peek([](auto elem) { std::cout << " - map    : " << elem << std::endl; });
  
  for (auto &elem : conseq2) {
    std::cout << "[out] : " << elem << std::endl;
  }
  
  return 0;
}
