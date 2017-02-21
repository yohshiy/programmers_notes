
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  vector<int> ary = { 3,2,9,6 };

  for (auto elem : ary) {
    cout << elem << endl;
  }

  
  for (auto itr = ary.begin() ; itr != ary.end() ; itr++) {
    cout << *itr << endl;
  }

  return 0;
}

