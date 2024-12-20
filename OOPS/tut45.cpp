#include<iostream>
using namespace std;



class  student{
    protected:
    int roll_no;
    public:
    void setnum(int num){
        roll_no = num;
    }
    void printnum(){
        cout<< "Your roll no is "<<roll_no<<"\n";
    }
};
class  test : virtual public student{
    protected:
    float maths;
    float physics;
    public:
    void setmarks(float m1,float m2){
        maths = m1;
        physics = m2;
    }
    void printmarks(){
        cout << "your result is:"<<"\n"
             << "Maths : " <<maths<<"\n"
             << "Physics : " << physics << "\n"; 
    }
};
class sport : virtual public student {
    protected:
    float score;
    public:
    void setscore(float sc){
        score = sc;
    }
    void printscore(){
        cout << "Your PT score is : " << score<<"\n";
    }
};
class result: public sport,public test{
    float total;
    public:
    void display(){
        printnum();
        printmarks();
        printscore();
        total = maths + physics + score;
        cout << "your total score is : " << total << "\n";
    }

};
int main(){

    result harry;
    harry.setnum(4200);
    harry.setmarks(78.9, 99.5);
    harry.setscore(9);
    harry.display();
    return 0;
}