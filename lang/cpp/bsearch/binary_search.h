
#ifndef __BINARY_SEARCH_H_LOADED__
#define __BINARY_SEARCH_H_LOADED__

#include <vector>


template <typename ElementType>
int binary_search(const std::vector<ElementType> &ary, ElementType key)
{
  const int KEY_NOT_FOUND = -1;
  int imin = 0;
  int imax = static_cast<int>(ary.size());

  for (;imin <= imax;) {
    int imid = imin + (imax - imin) / 2;
    if (ary[imid] > key) {
      imax = imid - 1;
    } else if (ary[imid] < key) {
      imin = imid + 1;
    } else {
      return imid;
    }
  }
  return KEY_NOT_FOUND;
}


template <class RandomIterator, typename T>
RandamIterator binary_search(RandamIterator first, RandamIterator last, const T &val)
{
  if (last <= first) {
    return last;
  }
  size_t bgnidx = 0;
  size_t endidx = last - first;

  for (;bgnidx <= endidx;) {
    size_t mididx = bgnidx + (endidx - bgnidx) / 2;
    const T &midval = *(first+mididx);
    if (midval < val) {
      bgnidx = mididx + 1;
    }
    else if (midval == val) {
      return first + mididx;
    }
    else {
      endidx = mididx - 1;
    }
  }
  return last;
}


#endif  // __BINARY_SEARCH_H_LOADED__

