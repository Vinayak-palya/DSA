0#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }

};
class Stack{
    Node* head;
    int capacity;
    int curr_size;
    public:
    Stack(int c){
        capacity = c;
        curr_size = 0;
        head = NULL;
    }
    bool isEmpty(){
        return (head == NULL);

    }
    bool isFull(){
        return (curr_size = capacity);
    }
    void push(int data){
        if(curr_size == capacity){
            cout<<"Overflow"<<endl;
            return ;
        }
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
        curr_size++;
    }
    int pop(){
        if(head == NULL){
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        Node* temp = head;
        head = head->next;
        int removed_data = temp->data;
        delete temp;
        return removed_data;
        
    }
    int size(){
        return curr_size;
    }
    int getTop(){
        if(head == NULL){
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        return head->data;
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