///
/// 範囲 for サンプル
///
/// g++ -std=c++14 for.cpp


#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;





int main()
{
  // STL コンテナー
  
  vector<int> ary = { 3,2,9,6 };
  
  for (auto elem : ary) {
    cout << elem << endl;
  }

  cout << endl;


  // 配列

  int cary[] = { 3,2,9,6 };
  
  for (auto elem : cary) {
    cout << elem << endl;
  }

  cout << endl;

  
  // 初期化リスト
  
  for (auto elem : { 3,2,9,6 }) {
    cout << elem << endl;
  }

  cout << endl;
  

  ////////////////////////////////////////////////////////////////

  vector<string> strs = { "foo", "bar", "baz" };
  
  for (auto &elem : strs) {
    elem += "!";
  }
  // { "foo!", "bar!", "baz!" }


  for (const auto &elem : strs) {
    cout << elem << endl;
  }

  cout << endl;


  ////////////////////////////////////////////////////////////////

  map<string, int> strmap = {
      { "foo", 3 },
      { "bar", 2 },
      { "baz", 9 }
  };
  for (const auto &elem : strmap) {
    cout << elem.first << " - " << elem.second << endl;
  }
    

  ////////////////////////////////////////////////////////////////

  for (auto itr = ary.begin() ; itr != ary.end() ; itr++) {
    auto elem = *itr;
    // 要素に対する処理
  }

  
  return 0;
}
