#include<iostream>
#include<vector>
using namespace std;
class Queue{
    int front;
    int back;
    vector<int> v;

public:
    Queue(){
        back = -1;
        front = -1;

    }
    void enqueue(int data){
        v.push_back(data);
        if(front == -1 and back == -1){
            
            front++;
            back++;
        }
        else back++;
        return;

    }
    void dequeue(){
        if(front == back){
            front = -1;
            back = -1;
            v.clear();
        }
        else front++;

    }
    int getfront(){
        return v[front];
    }
    bool isEmpty(){
        return front == -1;
    }
};
int main(){
    Queue qu;
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