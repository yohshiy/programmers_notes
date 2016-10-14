
#ifndef __BINARY_SEARCH_H_LOADED__
#define __BINARY_SEARCH_H_LOADED__

#include <vector>


template <typename T>
int binary_search(const std::vector<T> &ary, const T &val)
{
  const int NOT_FOUND = -1;
  int minidx = 0;
  int maxidx = static_cast<int>(ary.size()) - 1;

  while (minidx <= maxidx) {
    int mididx = minidx + (maxidx - minidx) / 2;
    if (ary[mididx] == val) {
      return mididx;
    }
    else if (ary[mididx] < val) {
      minidx = mididx + 1;
    }
    else {
      maxidx = mididx - 1;
    }
  }
  return NOT_FOUND;
}


template <class RandomIterator, typename T>
RandomIterator binary_search(RandomIterator first, RandomIterator last, const T &val)
{
  RandomIterator not_found = last;  

  while (first < last) {
    RandomIterator mid = first + (last - first) / 2;
    if (*mid == val) {
      return mid;
    }
    else if (*mid < val) {
      first = mid + 1;
    }
    else {
      last = mid;
    }
  }
  return not_found;
}


#endif  // __BINARY_SEARCH_H_LOADED__

