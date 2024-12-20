#include<iostream>
using namespace std;
class Stack{
    int top;
    int* arr;
    int capacity;
    public:
    Stack(int c){
        capacity = c;
        arr = new int[capacity];
        top = -1;
    }
    void push(int data){
        if(top == capacity - 1){
            cout<< "Overflow" <<endl;
            return;
        }
        top+=1;
        arr[top] = data;

    }
    int pop(){              // this can be of void type as well
        if(top == -1){
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        top--;
        return arr[top+1];
    }
    int getTop(){
        if(top == -1){
            cout<<"Unerflow"<<endl;
            return INT_MIN;
        }
        return arr[top];
    }
    bool isEmpty(){
        return (top == -1);
    }
    int size(){
        return top+1;
    }
    bool isFull(){
        return top = capacity - 1;
    }
};

int main(){
    Stack s(6);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.getTop()<<endl;
    s.push(5);
    s.push(6);
    cout<<s.getTop()<<endl;
    
    cout<< s.pop()<< endl;
    cout<<s.getTop()<<endl;




    return 0;
}