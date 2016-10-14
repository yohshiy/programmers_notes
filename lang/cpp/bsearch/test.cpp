

#include "binary_search.h"

#include <iostream>
#include <sstream>

using namespace std;


static int ToInt(const char *str)
{
  stringstream ss;
  ss << str;
  int val;
  ss >> val;
  return val;
}


static void Usage()
{
  cout << "example_bsearch SEARCH_NUM, NUM1 NUM2 ..." << endl;
}

int main(int argc, char **argv)
{
  std::vector<int> vec;

  if (argc < 3) {
    Usage();
    return 1;
  }

  int target = ToInt(argv[1]);
  cout << "Array [";
  for (int cnt = 2 ; cnt < argc ; cnt++) {
    if (cnt != 2) {
      cout << ", ";
    }
    vec.push_back(ToInt(argv[cnt]));
    cout << vec.back();
  }
  cout << "]" << endl;

  cout << "Find (" << target << ") => ";

  std::vector<int>::const_iterator itr = binary_search(vec.begin(), vec.end(), target);
  if (itr == vec.end()) {
    cout << "(Not found)";
  } else {
    cout << *itr;
  }
  cout << endl;
  
  return 0;
}

  
