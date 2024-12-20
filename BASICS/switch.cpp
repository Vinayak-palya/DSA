#include<iostream>
using namespace std;
int main(){
    int day;
    cin>>day;
    switch(day){
        case 1:
        cout<<"Monday"<<endl;
        break;
        case 2:
        cout<<"Tuesday"<<endl;
        break;
        case 3:
        cout<<"wednesday"<<endl;
        break;
        case 4:
        cout<<"Thursday"<<endl;
        break;
        case 5:
        cout<<"Friday"<<endl;
        break;
        case 6:
        cout<<"saturday"<<endl;
        break;
        case 7:
        cout<<"Sunday"<<endl;
        break;
        default:
        cout<<"Invalid"<<endl;
        break;
    }
    return 0;
}