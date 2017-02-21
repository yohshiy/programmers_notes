///
/// C++14 Streams サンプル
///
/// g++ -std=c++14 -I "Stream.h のあるパス" sample.cpp


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

namespace patch
{
    // Windows だと to_string はエラーがでるので作成
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
  std::cout << "{";
  seq | print_to(std::cout);
  std::cout << "}" << std::endl;
}

template <typename T>
void Dump(const T &val)
{
  std::cout << val << std::endl;
}



int main()
{
  vector<int> ary = { 3,2,9,6 };

  MakeStream::from(ary) |
      for_each([](auto elem) {
          cout << elem << endl;
        });

  // 作成
  ////////////////////////////////////////////////////////////////
  vector<int> vec = { 3,2,9,6 };
  int cary[] = { 3,2,9,6 };
  MakeStream::from(vec);
  MakeStream::from(cary, sizeof(cary)/sizeof(cary[0]));  // 配列はサイズも必要
  MakeStream::from({ 3,2,9,6 });                         // 初期化リストでも OK
  

  // 関数群
  ////////////////////////////////////////////////////////////////


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


  // count 
  Dump(MakeStream::from({3, 2, 9, 6}) | count());  // 4
  
  // limit
  auto limitseq =
      MakeStream::counter(1) | limit(3);  // {1 2 3}
  DumpStream(limitseq);

  // max 
  Dump(MakeStream::from({3, 2, 9, 6}) | max());  // 9
  // min 
  Dump(MakeStream::from({3, 2, 9, 6}) | min());  // 2

  // any, all
  std::cout << std::boolalpha;
  auto anyval =
      MakeStream::from({3, 2, 9, 6}) | any([](auto elem) { return (elem % 3) == 0;});  // true
  Dump(anyval);
  auto allval = 
      MakeStream::from({3, 2, 9, 6}) | all([](auto elem) { return (elem % 3) == 0;});  // false
  Dump(allval);

  // sort
  auto sortseq =
      MakeStream::from({3, 2, 9, 6}) | sort();  // {2 3 6 9}
  DumpStream(sortseq);

  
  // 四則演算
  auto divseq =
      MakeStream::from({3, 2, 9, 6}) / 3.0; // {1 0.666667 3 2}
  DumpStream(divseq);  

  auto mulseq =
      5 * MakeStream::from({3, 2, 9, 6}); // {15 10 45 30}
  DumpStream(mulseq);  

  auto modseq =
      MakeStream::from({3, 2, 9, 6}) % 3;  // {0 2 0 0}
  DumpStream(modseq);  

  auto vecplus =
      MakeStream::from({3, 2, 9}) + MakeStream::from({1, 2, 3}); // {3 4 27}
  DumpStream(vecplus);  

  // print_to
  MakeStream::from({3, 2, 9, 6}) | print_to(std::cout);  // 3 2 9 6

  
  //// 連結 1
  ////////////////////////////////////////////////////////////////
  // to_string() でエラーがでたので、ブログではボツ
  
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


  //// 連結 2
  ////////////////////////////////////////////////////////////////
  
  auto result =
      MakeStream::from({3, 2, 9, 6})
      | filter([](auto elem) { return elem % 2 == 1; })  // {3 9 }
      | map_([](auto elem)  { return elem * 2; })        // {6 18 }
      | reduce([](auto sum, auto elem) { return sum + elem; });  // 6+18 => 24
  Dump(result);

  auto resultvec =
      MakeStream::from({3, 2, 9, 6})
      | filter([](auto elem) { return elem % 2 == 1; })  // {3 9 }
      | map_([](auto elem)  { return elem * 2; })        // {6 18 }
      | to_vector();                                     // [6 18 ]

  std::cout << "[";
  for (auto &elem : resultvec) {
    std::cout << elem << " ";
  }
  std::cout << "]" << std::endl;

  
  //// 遅延評価の確認
  ////////////////////////////////////////////////////////////////
  
  std::cout << std::endl;
  auto lazyseq =
      MakeStream::from({3, 2, 9, 6})
      | peek([](auto elem) { std::cout << "[in]  : " << elem << std::endl; })
      | filter([](auto elem) { return elem % 2 == 1; })
      | peek([](auto elem) { std::cout << " - filter : " << elem << std::endl; })
      | map_([](auto elem)  { return elem * 2; })
      | peek([](auto elem) { std::cout << " - map    : " << elem << std::endl; });
  
  for (auto &elem : lazyseq) {
    std::cout << "[out] : " << elem << std::endl;
  }

  std::cout << std::endl;
  auto layseq_sort =
      MakeStream::from({3, 2, 9, 6})
      | peek([](auto elem) { std::cout << "[in]  : " << elem << std::endl; })
      | filter([](auto elem) { return elem % 2 == 1; })
      | peek([](auto elem) { std::cout << " - filter : " << elem << std::endl; })
      | sort()
      | peek([](auto elem) { std::cout << " - sort : " << elem << std::endl; })
      | map_([](auto elem)  { return elem * 2; })
      | peek([](auto elem) { std::cout << " - map    : " << elem << std::endl; });
  
  for (auto &elem : layseq_sort ) {
    std::cout << "[out] : " << elem << std::endl;
  }
  
  return 0;
}
