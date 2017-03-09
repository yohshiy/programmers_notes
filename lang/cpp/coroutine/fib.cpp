///
/// Boost コルーチン サンプル(フィボナッチ数)
///
///

#include <iostream>
#include <boost/coroutine2/coroutine.hpp>


/// フィボナッチ数
///
///     F(0) = 0
///     F(1) = 1
///     F(n) = F(n-1) + F(n-2)
/// 
void fibonacci(boost::coroutines2::coroutine<int>::push_type& yield)
{
    yield(0);
    yield(1);

    int prepre = 0;
    int pre = 1;
    for (int cnt = 0 ; cnt < 8 ; cnt++) {
        auto cur = prepre + pre;
        yield(cur);
        prepre = pre;
        pre = cur;
    }
}


void fibonacci_limit(boost::coroutines2::coroutine<int>::push_type& yield, int limit)
{    
    yield(0);
    yield(1);

    int prepre = 0;
    int pre = 1;
    for (int cnt = 0 ; cnt < limit ; cnt++) {
        auto cur = prepre + pre;
        yield(cur);
        prepre = pre;
        pre = cur;
    }
}


int main()
{
    boost::coroutines2::coroutine<int>::pull_type source(fibonacci);

    for (auto num : source) {
        std::cout << num <<  " ";
    }
    std::cout << std::endl;

    
    source = boost::coroutines2::coroutine<int>::pull_type(fibonacci);
    for (; source ; source()) {
        std::cout << source.get() <<  " ";
    }
    std::cout << std::endl;

    

    boost::coroutines2::coroutine<int>::pull_type source2(
        [](auto & yield){fibonacci_limit(yield, 10);});

    for (auto num : source2) {
        std::cout << num <<  " ";
    }
    std::cout << std::endl;
    
    return 0;
}

