#include <iostream>
using namespace std;

class complex
{
    int real, imaginary;

public:
    void setdata(int a, int b)
    {
        real = a;
        imaginary = b;
    }
    void getdata()
    {
        cout << "the real part is " << real << endl;
        cout<< "the imaginary part is " << imaginary << endl;
    }
};
int main()
{
    complex *ptr = new complex;
    // (*ptr).setdata(1,54); 
    // (*ptr).getdata();is as good as
    ptr->setdata(1,54);
    ptr->getdata();

    complex *ptr1 = new complex[3];
    ptr1->setdata(1,4);
    ptr1->getdata();
    (ptr+1)->setdata(2,5);
    (ptr+1)->getdata();
    (ptr+2)->setdata(3,7);
    (ptr+2)->getdata();
    
    return 0;
}