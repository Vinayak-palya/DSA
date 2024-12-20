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

//asuming k is always less than equal to length of the linkedlist
void removeKTHNodefromrend(Node* &head,int k){
    Node* ptr1 = head;
    Node* ptr2 = head;
    int count = k;

    //move ptr2 ksteps ahead;

    while(count--){
        ptr2 = ptr2->next;
    }

    if(ptr2 == NULL){
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    // now ptr2 is ksteps ahead
    while(ptr2->next != NULL){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

    }
    Node* temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    free(temp);

}



int main(){
    Linkedlist LL1;
    LL1.InsertAtTail(1);
    LL1.InsertAtTail(2);
    LL1.InsertAtTail(3);
    LL1.InsertAtTail(4);
    LL1.InsertAtTail(5);
    LL1.InsertAtTail(6);
    LL1.display();

    removeKTHNodefromrend(LL1.head,3);
    LL1.display();

    
    return 0;
}