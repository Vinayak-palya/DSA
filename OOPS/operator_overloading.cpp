#include<iostream>
using namespace std;
class complex{
    public:
    int real;
    int img;
    complex(int x,int y){
        real = x;
        img = y;

    }
    complex operator+ (complex &c){
        complex ans(0,0);
        ans.real = real + c.real;
        ans.img = img + c.img;
        return ans;
    }
};
int main(){
    complex c1(1,2);
    complex c2(1,3);
    complex c3 = c1 + c2;
    
    cout<<c3.real<<" + i"<<c3.img<<"\n";
    return 0;
}