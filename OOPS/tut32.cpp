#include <iostream>
using namespace std;

class simple
{
    int data1, data2, data3;

public:
    simple(int a, int b = 8, int c = 9)
    {
        data1 = a;
        data2 = b;
        data3 = c;
    }
    void print();
};
void simple ::print()
{
    cout << "the value of data1 ,data2,data3 is respectively " << data1 << " , " << data2 << " , " << data3 << "\n";
}
int main()
{
    simple s1(2), s2(2, 3), s3(2, 3, 4);
    ;

    s1.print();

    s2.print();

    s3.print();
    return 0;
}
