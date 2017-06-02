
#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

#if 0
// 貼り付け用

template< bool B, class T = void >
struct enable_if;

template< bool B, class T = void >
using enable_if_t = typename enable_if<B,T>::type;

#endif


template <typename T>
void FooFunc(T val) {}

template <typename T>
typename T::size_type GetSize(const T &vec)
{
  return vec.size();
}


#if _INT_ONLY

/// 結果を切り捨てる割り算
int FloorDivide(int num, int deno)
{
  int ans = num / deno;
  return ((0 < num * deno) || (num % deno == 0)) ? ans : ans - 1;
}


#elif _ALL

/// 結果を切り捨てる割り算
template <typename T>
T FloorDivide(T num, T deno)
{
  T ans = num / deno;
  return ((0 < num * deno) || (num % deno == 0)) ? ans : ans - 1;
}


#elif _INTEGRAL_ONLY_LONG

/// 結果を切り捨てる割り算
template <typename T, class U = typename std::enable_if<std::is_integral<T>::value>::type >
T FloorDivide(T num, T deno)
{
  T ans = num / deno;
  return ((0 < num * deno) || (num % deno == 0)) ? ans : ans - 1;
}




#elif _INTEGRAL_ONLY

/// 結果を切り捨てる割り算
template <typename T, class = std::enable_if_t<std::is_integral<T>::value> >
T FloorDivide(T num, T deno)
{
  T ans = num / deno;
  return ((0 < num * deno) || (num % deno == 0)) ? ans : ans - 1;
}




#elif _UNSIGNED

/// 結果を切り捨てる割り算(符号なし版)
template <typename T, class = std::enable_if_t<std::is_unsigned<T>::value> >
T FloorDivide(T num, T deno)
{
  return num / deno;
}

/// 結果を切り捨てる割り算(符号あり版)
template <typename T, class = std::enable_if_t<!std::is_unsigned<T>::value> >
T FloorDivide(T num, T deno)
{
  T ans = num / deno;
  return ((0 < num * deno) || (num % deno == 0)) ? ans : ans - 1;
}


#elif _FIN

/// 結果を切り捨てる割り算(符号なし版)
template <typename T, class = std::enable_if_t<std::is_unsigned<T>::value> >
T FloorDivide(T num, T deno)
{
  return num / deno;
}


/// 結果を切り捨てる割り算(符号あり版)
template <typename T, class = std::enable_if_t<std::is_signed<T>::value && std::is_integral<T>::value> >
T FloorDivide(T num, T deno)
{
  int ans = num / deno;
  return ((0 < num * deno) || (num % deno == 0)) ? ans : ans - 1;
}

#else

/// 結果を切り捨てる割り算(符号なし版)
template <typename T, class = std::enable_if_t<std::is_unsigned<T>::value> >
T FloorDivide(T num, T deno)
{
  return num / deno;
}

template <typename T, typename U,
          class = std::enable_if_t<std::is_signed<T>::value && std::is_integral<T>::value>,
          class = std::enable_if_t<std::is_signed<T>::value && std::is_integral<U>::value> >
auto FloorDivide(T num, U deno)
{
  auto ans = num / deno;
  return ((0 < num * deno) || (num % deno == 0)) ? ans : ans - 1;
}

#endif




////////////////////////////////////////////////////////////////


template <typename T>
void OutFloorDivision(T num, T deno)
{
  cout << num << " / " <<  deno << " -> ";
  cout << FloorDivide(num, deno);
  cout << endl;
}


int main()
{
  FooFunc(3);
  GetSize(std::vector<int>());  // std::vector<int>::size_type
  // GetSize(3);                   // int::size_type
    
  FloorDivide( 3,  2);  //  3/ 2 =  1.5 -> 1
  FloorDivide(-3, -2);  // -3/-2 =  1.5 -> 1
  FloorDivide(-5,  2);  // -5/ 2 = -2.5 -> -3

  FloorDivide( 3U,  2U);
    
  OutFloorDivision( 3,  2);
  OutFloorDivision(-3, -2);
  OutFloorDivision(-5,  2);
  OutFloorDivision( 5, -2);
  OutFloorDivision(-2,  3);
  OutFloorDivision( 3,  5);
  OutFloorDivision( 0,  5);

  OutFloorDivision( 3U,  2U);
  // OutFloorDivision( 3.2,  2.0);

    
  return 0;
}

