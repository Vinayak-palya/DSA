#include <iostream>
using namespace std;
// Destructor never takes an argument nor does it return any value
int counter = 0;
class num
{
public:
    num()
    {
        counter++;
        cout << "This is the time when constructor is called for object number" << counter << endl;
    }
    ~num()
    {

        cout << "This is the time when my destructor is called for object number" << counter << endl;
        counter--;
    }
};

int main()
{

    cout << "We are inside our main function" << endl;
    cout << "Creating first object n1" << endl;
    num n1;
    {
        cout << "Entering this block" << endl;
        cout << "Creating two more objects" << endl;
        num n2, n3;
        cout << "Exiting this block" << endl;
    }
    cout << "Back to main" << endl;

    return 0;
}