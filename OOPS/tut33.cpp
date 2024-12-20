#include <iostream>
using namespace std;
class BankDeposit{
    int principal;
    int time;
    float rate;
    float returnvalue;
public:
    BankDeposit(){}
    BankDeposit(int ,int ,int );
    BankDeposit(int ,int ,float );
    void show();
};
BankDeposit :: BankDeposit(int p,int t,int r){
    principal = p;
    time = t;
    rate = float(r)/100;
    returnvalue = principal;
    for(int i = 0;i < time;i++){
        returnvalue = returnvalue*(1+rate);
    }
}
BankDeposit :: BankDeposit(int p,int t,float r){
    principal = p;
    time = t;
    rate = r;
    returnvalue = principal;
    for(int i = 0;i < time;i++){
        returnvalue = returnvalue*(1+rate);
    }
}
void BankDeposit :: show(){
    cout<<endl<<"Principal amount was "<<principal
        << ". Return value after "<<time
        << " years is "<<returnvalue<<endl;
}


int main()
{
    BankDeposit bd1,bd2,bd3;
    int p,y;
    float r;
    int R;
    cin>>p>>y>>r;
    bd1 = BankDeposit(p,y,r);
    bd1.show();
    cin>>p>>y>>R;
    
    bd2 = BankDeposit(p,y,R);
    bd2.show();
    return 0;
}