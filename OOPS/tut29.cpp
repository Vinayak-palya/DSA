#include<iostream>
using namespace std;

class complex{
    int a,b;
    public:
    // Creating a Constructor
    // Constructor is a special member function with the same name as of the class.
    //It is used to initialize the objects of its class
    //It is automatically invoked whenever an object is created

    
    complex();//constructor declaration

    void printdata(){
        cout<<"The given complex number is:"<<a<<" + i"<<b<<endl;
    }
};
complex :: complex(){// --> default constructor and takes no input value
    a = 12;
    b = 2;
}




int main(){
    complex c;
    c.printdata();
    return 0;
}
/* characteristics of a constructor

1. It should be declared in the public section of the class.
2. They are automatically invoked whenever the object is created.
3. They cannot return values and they do not have return types.
4. It cannot have default parameters.
5. We cannot refer to their address.
6. We can have multiple constructor for the same object of a class. -- > this is called as constructor overloading.
*/