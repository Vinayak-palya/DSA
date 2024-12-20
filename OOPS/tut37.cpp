#include <iostream>
using namespace std;

// Base class
class Employee
{
public:
    int id;
    float salary;
    Employee(int inpid)
    {
        salary = 34.0;
        id = inpid;
    }
    Employee() {}
};
// creating a derived class  --> programmer  from base class --> employee



 // Derived Class syntax
/*
class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}}
{
    class members/methods/etc...
};
*/

/*
1. Defaultvisibility mode is private.
2. Public visibility mode : public member of the base class become public member of the derived class.
3. Private visibility mode : Public member of the base class become the  private member of the derived class.
4. private members are never inherited.


*/


class Programmer : public Employee
{
public:
    int language_code;
    Programmer(int inpid)
    {
        id = inpid;
        language_code = 9;
        salary = 34.0;
    }

    void getdata()
    {
        cout << id << endl;
    }
};

int main()
{
    Employee harry(1), rohan(2);
    cout << harry.salary << endl;
    cout << rohan.salary << endl;
    Programmer skillF(10);
    cout << skillF.language_code << endl;
    cout << skillF.id << endl;
    cout<< skillF.salary << endl;
    skillF.getdata();

    return 0;
}