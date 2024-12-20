#include <iostream>
using namespace std;

/*
class derived :visibility mode baseclass-1,visibility mode baseclass-2
{
    class body of class "derived".
}
*/
class base_1
{
protected:
    int data1;

public:
    void setdata1(int num1)
    {
        data1 = num1;
    }
};
class base_2
{

protected:
    int data2;

public:
    void setdata2(int num2)
    {
        data2 = num2;
    }
};
class derived : public base_1, public base_2
{
protected:
    int data3;

public:
    void setdata3(int num3)
    {
        data3 = num3;
    }
    void show()
    {
        cout << "The value of data1 is " << data1 << endl;
        cout << "The value of data2 is " << data2 << endl;
        cout << "The value of data3 is " << data3 << endl;
        cout << "The sum of all the data is " << data1 + data2 + data3 << endl;
    }
};
/*
The inherited base class will look like
Data members :
    data1 --> protected
    data2 --> protected
    Member Functions:
    setdata1 --> public
    setdata2 --> public
    setdata3 --> public




*/

int main()
{
    derived d;
    d.setdata1(15);
    d.setdata2(5);
    d.setdata3(25);
    d.show();

    return 0;
}