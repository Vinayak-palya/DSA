
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
Node* reverseLLrec(Node* &head){
    //base case
    if( head->next == NULL){//if(head == null || head->next == null)
        return head;
    }  



    //recursive case
    Node* new_head = reverseLLrec(head->next);
    head->next->next = head;
    head->next = NULL;

return new_head;
}

int main(){
    Linkedlist ll;
    ll.InsertAtTail(1);
    ll.InsertAtTail(2);
    ll.InsertAtTail(3);
    ll.InsertAtTail(4);
    // ll.InsertAtTail(5);
    ll.display();
    
    

    ll.head = reverseLLrec(ll.head) ;
    ll.display();

    return 0;
}