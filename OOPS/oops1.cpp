#include<iostream>
using namespace std;
class Fruit{
    public://acess specifier for directly accessing in main function
    string name;
    string color;

};

int main(){
    Fruit apple;//object
    apple.name = "Apple";
    apple.color = "Red";
    cout<<apple.name<<" - "<<apple.color<<" ";
    Fruit *mango = new Fruit();
    mango->name = "Mango";
    mango->color = "Yellow";
    cout<<mango->name<<" - "<<mango->color<<" ";
    return 0;
}