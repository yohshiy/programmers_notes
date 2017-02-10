#include <iostream>
#include <queue>

struct less_digit
{
  bool operator()(int x, int y) const
  {
    return (x%10) < (y%10);
  }
};

using namespace std;

int main()
{
  priority_queue<int,deque<int>,less_digit> pq;
  for ( int i = 0; i < 30; ++i ) {
    pq.push(i);
  }

  while ( !pq.empty() ) {
    cout << pq.top() << ' ';
    pq.pop();
  }
  cout << endl;
}
