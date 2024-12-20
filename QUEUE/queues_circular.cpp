#include<iostream>
#include<vector>
using namespace std;
class Queue{
    int front;
    int back;
    vector<int> v;
    int cs;

public:
    Queue(int n){
        v.resize(n);
        back = n-1;
        front = 0;
        cs = 0;

    }
    void enqueue(int data){
        if(isFull()) return;
        back = (back + 1)%v.size();
        v[back] = data;
        cs++;
    }
    void dequeue(){
        if(isEmpty()) return ;
        front = (front+1)%v.size();
        cs--;
    }
    int getfront(){
        return v[front];
    }
    bool isEmpty(){
        return cs == 0;
    }
    bool isFull(){
        return cs == v.size();
    }
};
int main(){
    Queue qu(3);
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.dequeue();
    qu.enqueue(40);
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    qu.enqueue(400);
    qu.enqueue(500);
    while(!qu.isEmpty()){
        cout<<qu.getfront()<<endl;
        qu.dequeue();
    }
    return 0;
}