#include <iostream>
using namespace std;

class Base1
{
public:
    void greet()
    {
        cout << "Hello peoples" << "\n";
    }
};
class Base2
{

public:
    void greet()
    {
        cout << "kaise hai aap log" << "\n";
    }
};
class derived : public Base1, public Base2
{
public:
    void greet()
    {
        Base2 ::greet();
    }
};
class B
{
public:
    void say()
    {
        cout << "Hello world to c++ language" << endl;
    }
};
class D : public B
{
public:
    void say()
    {
        cout << "hello duniya" << "\n"; // D's new say() method will override base class's say() method
    }
};
int main()
{
    Base1 o1;
    Base2 o2;
    derived d;
    o1.greet();
    o2.greet();
    d.greet();
    D od;
    od.say();
    return 0;
}