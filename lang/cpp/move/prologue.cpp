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

void SwapEffectiveMore(string &a, string &b)
{
  string tmp = std::move(b);
  b = std::move(a);
  a = std::move(tmp);
}





int main()
{
  string src = "Hello";
  auto newstr = ToUpperString(src);

  cout << ToUpperString(src) << endl;
  cout << ToUpperStringEffective(src) << endl;

    
  ////////////////////////////////////////////////////////////////

  cout << endl;
  cout << "# Swap" << endl;
  
  string astr = "Hello", bstr = "World";

  cout << astr << " " << bstr << endl;

  Swap(astr, bstr);
  cout << astr << " " << bstr << endl;
    
  SwapEffective(astr, bstr);
  cout << astr << " " << bstr << endl;

  SwapEffectiveMore(astr, bstr);
  cout << astr << " " << bstr << endl;


  //// 右辺値のサンプル
  ////////////////////////////////////////////////////////////////

  cout << endl;
  cout << "# RValue" << endl;

  int num = 5;         // リテラル 5
  int num2 = num * 2;  // 計算結果 10 (num*2)
  
  // 3 = num;
  // num * 2 = 7;

  cout << 3 << endl;
  cout << num * 2 << endl;
  cout << string("Hello") << endl;  // string("Hello") はすぐに解放
  
  return 0;
}
