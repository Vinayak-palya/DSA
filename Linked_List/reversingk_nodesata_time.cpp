#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int num){
        val = num;
        next = NULL;
        
    }

};
class Linkedlist{
    public:
    Node* head;
    Linkedlist(){
        head = NULL;

    }
    void InsertAtTail(int value){

        Node* new_node = new Node(value);

        if(head == NULL){
            head = new_node;
            return ;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<"->";
            temp = temp->next;

        }
        cout<<"NULL"<<endl;
    }
};

Node* reverseLL(Node* &head){
    Node* prevptr = NULL;
    Node* currptr = head;
    while(currptr != NULL){
        Node* next = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = next;

    }
    Node* new_head = prevptr;
    return new_head;
}
Node* reversekLL(Node* head,int k){
    Node* prevptr = NULL;
    Node* currptr = head;
    int counter = 0;
    while(currptr != NULL && counter < k){
        Node* next = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = next;
        counter++;

    }
    //curr ptr will give us(k+1)th node
    if(currptr!= NULL){
        Node* new_head = reversekLL(currptr,k);//recursive calls
        head->next = new_head;
    }
    return prevptr;//prevptr will give us the new head of the connected linkedlist
}
int main(){
    Linkedlist ll;
    ll.InsertAtTail(1);
    ll.InsertAtTail(2);
    ll.InsertAtTail(3);
    ll.InsertAtTail(4);
    ll.InsertAtTail(5);
    ll.InsertAtTail(6);
    ll.display();
    
    

    ll.head = reversekLL(ll.head,2) ;
    ll.display();

    return 0;
}