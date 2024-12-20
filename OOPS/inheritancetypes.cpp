#include<iostream>
using namespace std;
class parent{
    public:
    parent(){
        cout<<"parent class"<<endl;
    }
};
// class parent2{
//     public:
//     parent2(){
//         cout<<"parent2 class"<<endl;
//     }
// };

class child1: public parent{
    public:
    child1(){
        cout<<"child1 class "<<"\n";
    }
};
class child2: public parent{
    public:
    child2(){
        cout<<"child2 class "<<"\n";
    }
};
class grandchild: public child1,public child2{
    public:
    grandchild(){
        cout<<"grandchild class"<<"\n";
    }
};
int main(){
    grandchild c;
    return 0;
}