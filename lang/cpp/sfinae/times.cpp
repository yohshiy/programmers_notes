
#include <iostream>
#include <string>




template <class T>
auto check_multipliable(T*) -> decltype(std::declval<T>() * 1, std::true_type());

template <class T>
auto check_multipliable(...) -> std::false_type;


template <class T>
struct is_multipliable : decltype(check_multipliable<T>(nullptr)) {};



template <typename T, typename std::enable_if_t<is_multipliable<T>::value, std::nullptr_t> = nullptr>
T Times(const T &val, int num)
{
    return val * num;
}

template <typename T, typename std::enable_if_t<!is_multipliable<T>::value, std::nullptr_t> = nullptr>
T Times(const T &val, int num)
{
    T ret = T();
    for (int cnt = 0 ; cnt < num ; cnt++) {
        ret += val;
    }
    return ret;
}


template <typename T, typename std::enable_if_t<!is_multipliable<T>::value, std::nullptr_t> = nullptr>
T operator*(const T &val, int num)
{
    std::cout << " T ";
    return Times(val, num);
}



using namespace std;

int main()
{
    cout << "3 * 2 = " << Times(3,2) << endl;
    cout << "3.5 * 2 = " << Times(3.5, 2) << endl;
    cout << "3.5 * -2 = " << Times(3.5, -2) << endl;
    cout << "Hi * 2 = " << Times("Hi"s, 2) << endl;
    cout << "Hi * 2 = " << ("Hi"s * 2) << endl;
    cout << "10 * 2 = " << (10 * 2) << endl;
    return 0;
}
