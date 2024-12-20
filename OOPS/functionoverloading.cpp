#include<iostream>
using namespace std;
class sum{
    public:
    void add(int x,int y){
        int sum = x + y;
        cout<<sum<<endl;
    }
    void add(int x,int y,int z){
        int sum  = x + y + z;
        cout<<sum<<endl;
    }
    void add(float x,float y){
        float sum = x + y;
        cout<<sum<<endl;
    }
};
int main(){
    sum s;
    s.add(2,3.5);
    s.add(float(2.0),float(3.5));

    return 0;
}