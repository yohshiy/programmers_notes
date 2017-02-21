

#include <iostream>
#include <iterator>

#include "Stream.h"
using namespace std;
using namespace stream;


int main()
{
  auto seq = MakeStream::from(istream_iterator<int>(cin), istream_iterator<int>());
  cout << endl;
  for (const auto &elem : seq) {
    cout << elem << endl;
  }

  return 0;
}
