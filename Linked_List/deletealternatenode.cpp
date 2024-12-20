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
void deletealternatenode(Node* &head){
    Node* curr_node = head;
    while(curr_node != NULL  &&  curr_node->next != NULL){// if we will just check second condition first 
    // and first condition after that than it will have some undefined behaviour
        Node* temp = curr_node->next;
        curr_node->next = curr_node->next->next;
        free(temp);
        curr_node = curr_node->next;
        }

}
int main(){
    Linkedlist ll;
    ll.InsertAtTail(1);
    ll.InsertAtTail(2);
    ll.InsertAtTail(3);
    ll.InsertAtTail(4);
    ll.InsertAtTail(5);
    ll.display();
    
    deletealternatenode(ll.head);
    ll.display();



    return 0;
}