#include<iostream>
#include "../include/log.h"
using namespace std;
class MyClass
{
public:
    MyClass(int i = 0)
    {
        cout <<"a"<< i;
    }
    MyClass(const MyClass &x)
    {
        cout << 2;
    }
    MyClass &operator=(const MyClass &x)
    {
        cout << 3;
        return *this;
    }
    ~MyClass()
    {
        cout << 4;
    }
};
int main()
{
    MyClass obj1(1), obj2(2);
    MyClass obj3 = obj1;
    
    CHECK(2==2)<<"相等吗？";
    INFO << 12335 <<"DUZEJIE TEST";
    CHECK(3==3) <<"相等吗？"<<"相等吗？"<<"相等吗？";
    CHECK(3==4) << "3与4不相等"<< "3与4不相等"<<3<<4;
    return 0;
}