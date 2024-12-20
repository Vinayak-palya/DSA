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

bool checkEqualLL(Node* head1,Node* head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    while(ptr1 != NULL  && ptr2 != NULL){
        if(ptr1->val != ptr2->val) return false;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

    }
    if(ptr1 == NULL && ptr2 == NULL){
        return true;
    }
    return false;

}

int main(){
    Linkedlist LL1;
    LL1.InsertAtTail(1);
    LL1.InsertAtTail(2);
    LL1.InsertAtTail(3);

    Linkedlist LL2;
    LL2.InsertAtTail(1);
    LL2.InsertAtTail(2);
    LL2.InsertAtTail(3);
    LL2.InsertAtTail(4);

    LL1.display();
    LL2.display();
    cout<<checkEqualLL(LL1.head,LL2.head)<<endl;

    return 0;
}