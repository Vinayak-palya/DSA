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
int getlength(Node* head1){
    int length = 0;
    while(head1 != NULL){
        length++;
        head1 = head1->next;

    }
    return length;
}
Node* moveheadbykstep(Node* &head,int k){
    Node* ptr = head;
    while(k--){
        ptr = ptr->next;
    }
    return ptr;
}

Node* getIntersection(Node* head1,Node* head2){
   
    //step1: calculate length of both the linkedlist
    int l1 = getlength(head1);
    int l2 = getlength(head2);
    //step2: find differnce between linkedlistand movelongerlinkedlist pointer to k steps
    Node* ptr1,*ptr2;
    if(l1 > l2){
        int k = l1 - l2;
        ptr1 = moveheadbykstep(head1,k);
        ptr2 = head2;
    }
    else{
        int k = l2 - l1;
        ptr1 = head1;
        ptr2 = moveheadbykstep(head2,k);

    }
    while(ptr1){
        if(ptr1 == ptr2){
            return ptr1;

        }
        else{
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;

        }
    }
    return NULL;

}
int main(){
    Linkedlist LL1;
    LL1.InsertAtTail(1);
    LL1.InsertAtTail(2);
    LL1.InsertAtTail(3);
    LL1.InsertAtTail(4);
    LL1.InsertAtTail(5);
    LL1.InsertAtTail(6);
    

    Linkedlist LL2;
    LL2.InsertAtTail(6);
    LL2.InsertAtTail(7);
    LL2.head->next->next =LL1.head->next->next->next;

    LL1.display();
    LL2.display();
    Node* intersection = getIntersection(LL1.head,LL2.head);
    if(intersection){
        cout<<intersection->val<<" ";

    }
    else{
        cout<<"-1"<<endl;
    }

    return 0;
}