//
// sum : 可変長引数関数のサンプル
//
// g++ -std=c++11 sum.cpp 


#include <iostream>


////////////////////////////////////////////////////////////////
//// 整数の合計
////////////////////////////////////////////////////////////////

// 末端 isum
inline int isum()
{
  return 0;
}

// 再帰呼び出し isum
template<typename First, typename... Rest>
int isum(const First& first, const Rest&... rest)
{
  return first + isum(rest...);
}


////////////////////////////////////////////////////////////////
//// 任意の型の合計
////////////////////////////////////////////////////////////////

template<typename Ret>
Ret any_sum()
{
  return Ret();
}
 
template<typename Ret, typename First, typename... Rest>
Ret any_sum(const First& first, const Rest&... rest)
{
  return first + any_sum<Ret>(rest...);
}


////////////////////////////////////////////////////////////////
//// 文字列の結合
////////////////////////////////////////////////////////////////
#include <sstream>

inline void concat_internal(std::stringstream &sout)
{
}
 
template<typename First, typename... Rest>
void concat_internal(std::stringstream &sout, const First& first, const Rest&... rest)
{
  sout << first;
  concat_internal(sout, rest...);
}


template<typename... Args>
std::string concat(const Args&... args)
{
  std::stringstream sout;
  concat_internal(sout, args...);
  return sout.str();
}





////////////////////////////////////////////////////////////////
//// 使用例
////////////////////////////////////////////////////////////////

using namespace std;

int main()
{
  cout << isum(1, 2, 3, 4) << endl;         // 10
  cout << isum(1.0, 2.2, 3.3, 4.9) << endl; // 10
                                            // = 1.0 + 2 + 3 + 4 + isum()

  cout << any_sum<int>(1.0, 2.2, 3.3, 4.9) << endl;    // 10
  cout << any_sum<double>(1.0, 2, 3.3, 4.9) << endl;   // 11.2
  cout << any_sum<string>("Hello", " ", "world", "!") << endl;  // "Hello world!"
  // cout << any_sum<string>("Hello ", "world", 3) << endl;  // コンパイルエラー

  cout << concat("Hello ", "world ", 3, " ", 1.2) << endl;  // "Hello world 3 1.2"
  
  return 0;
}

