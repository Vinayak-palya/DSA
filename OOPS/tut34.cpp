#include <iostream>
using namespace std;
class Number
{
    int a;

public:
    Number()
    {
        a = 0;
    }
    Number(int num)
    {
        a = num;
    }
    Number(Number &obj)
    {
        this->a = obj.a;
    }
    void display()
    {
        cout << "The number of  this object is " << a << endl;
    }
};

int main()
{
    Number x, y, z(45), z2;
    x.display();
    y.display();
    z.display();

    Number z1(z); // copy constructor invoked;
    z1.display();

    z2 = z;
    z2.display(); // copy constructor not called;

    Number z3 = z;
    z3.display(); // copy constructor invoked;

    return 0;
}