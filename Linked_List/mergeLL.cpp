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

Node* mergeLL(Node* &head1,Node* &head2){
    Node* dummyheadnode = new Node(-1);
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* ptr3 = dummyheadnode;
    while(ptr1 && ptr2){
        if(ptr1->val < ptr2->val){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;

        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    if(ptr1){
        ptr3->next = ptr1;

    }
    else{
        ptr3->next = ptr2;
    }
    return dummyheadnode->next;
}



int main(){
    Linkedlist LL1;
    LL1.InsertAtTail(1);
   
    LL1.InsertAtTail(5);
    LL1.InsertAtTail(6);
    // LL1.display();

    Linkedlist LL2;
    LL2.InsertAtTail(2);
    LL2.InsertAtTail(3);
    LL2.InsertAtTail(4);
    Linkedlist ll3;
    ll3.head = mergeLL(LL1.head,LL2.head);
    ll3.display();
    
    return 0;
}