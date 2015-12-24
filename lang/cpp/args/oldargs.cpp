
#include <stdarg.h>
#include <stdio.h>


int unsafe_isum(int argnum, ...)
{
  va_list arg;
  int sum = 0;
  
  va_start(arg, argnum);

  // 引数の数だけ繰り返し
  for (int cnt = 0; cnt < argnum ; cnt++)
  {
    // int として処理
    sum += va_arg(arg, int);
  }

  va_end(arg);
  
  return sum;
}


void unsafe_printf(const char *fmt, ...)
{
  va_list arg;

  va_start(arg, fmt);
  ::vprintf(fmt, arg);
  va_end(arg);
}


int main()
{
  // 使用例
  printf("sum = %d\n", unsafe_isum(3, 1, 2, 3));  // 9
  unsafe_printf("Hello %s, %02d, %.3f\n", "world", 3, 1.2);  // "Hello world, 03, 1.200"
  
  return 0;
}
