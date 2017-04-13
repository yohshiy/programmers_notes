

#include <iostream>
#include <string>

using namespace std;

void foo(const string &str)
{
    cout << " (not right) " << str << endl;
}

void foo(string &&str)
{
    cout << " (right) " << str << endl;
}



int main()
{
    string var("var");
    foo(var);
    foo("literal"s);
    
    
    return 0;
}
