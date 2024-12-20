#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
class Queue{
    Node* head;
    Node* tail;
    int size;
    public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;

    }
    void enqueue(int data){
        Node* new_node = new Node(data);
        if(head == NULL){
            head = tail = new_node;
            
        }
        else{
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }
    void dequeue(){
        if(head == NULL){
            return ;
        }
        else{
            Node* temp = head;
            head = head->next;
            if(head == NULL) tail = NULL;
            delete temp;
            size--;

        }
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return head == NULL;
    }
    int front(){
        if(head == NULL) return -1;
        return head->data;
    }
};

int main(){
    Queue qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.dequeue();
    qu.enqueue(40);
    while(!qu.isEmpty()){
        cout<<qu.front()<<endl;
        qu.dequeue();
    }
    return 0;
}