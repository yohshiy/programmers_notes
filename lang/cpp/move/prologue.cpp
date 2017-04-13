/// @file
/// move 説明用コード
/// 
/// コンパイル
///     g++ -std=c++14 prologue.cpp
/// 

#include <iostream>
#include <string>
#include <cctype>

using namespace std;


//// 戻り値でコピーが発生するサンプル
////////////////////////////////////////////////////////////////

string ToUpperString(const string &src)
{
  string dest;

  for (auto ch : src) {
    dest.push_back(::toupper(ch));
  }
  return dest;
}

string ToUpperStringEffective(const string &src)
{
  string dest;

  for (auto ch : src) {
    dest.push_back(::toupper(ch));
  }
  return std::move(dest);
}


//// Swap 
////////////////////////////////////////////////////////////////

void Swap(string &a, string &b)
{
  string tmp = b;
  b = a;
  a = tmp;
}

void SwapEffective(string &a, string &b)
{
  string tmp = b;
  b = a;
  a = std::move(tmp);
}





int main()
{
  string src = "Hello";

  cout << ToUpperString(src) << endl;
  cout << ToUpperStringEffective(src) << endl;

    
  ////////////////////////////////////////////////////////////////

  cout << endl;
  cout << "# Swap" << endl;
    
  string foo = "Hello", bar = "World";

  cout << foo << " " << bar << endl;

  Swap(foo, bar);
  cout << foo << " " << bar << endl;
    
  SwapEffective(foo, bar);
  cout << foo << " " << bar << endl;

  return 0;
}
