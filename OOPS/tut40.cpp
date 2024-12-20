#include<iostream>
using namespace std;
class student{
    // protected:
    int roll_no;
    public:
    void set_roll_no(int);
    void display();

};
void student :: set_roll_no(int r){
    roll_no = r;
}
void student :: display(){
    cout<<"The roll no.  is :"<<roll_no<<endl;
}
class marks : public student{
    protected:
    float maths;
    float physics;
    public:
    void set_marks(float ,float);

};
void marks :: set_marks(float m,float p){
    maths = m;
    physics  = p;
}
class result : public marks{
    float percentage;
    public:
    void display_result();


};
void result :: display_result(){

    cout<<"The percentage marks scored is:"<<(maths + physics)/2<<"%"<<endl;
}


int main(){
    /*
    Notes:
    If we are inheriting B from A and C from B;
    1. A is the base class for B and B is the base class for C.
    2.A-->B-->C is called the inheritance path.
   
    */
    result vinayak;
    vinayak.set_roll_no(148);
    vinayak.display();
    vinayak.set_marks(97.0 , 93.5);
    vinayak.display_result();


    return 0;
}