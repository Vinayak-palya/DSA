#include<iostream>
using namespace std;
class Shop{

    int id;
    float price;
    public : 
    void setdata(int a,float b){
        id = a;
        price  = b;

    }
    void getdata(){
        cout<< "the article no of the item is "<< id << endl;
        cout<< "the price of this article  is " << price <<endl;

        }
};
int main(){
    int size,p;
    float q;
    cin>>size;
    Shop *ptr = new Shop[size];
    Shop *ptrTemp = ptr;
    for(int i = 0;i < size;i++){
        cin>>p>>q;
        ptr->setdata(p,q);
        ptr++;

    }
    for(int j = 0;j < size;j++){
        ptrTemp->getdata();
        ptrTemp++;
    }
    return 0;
}