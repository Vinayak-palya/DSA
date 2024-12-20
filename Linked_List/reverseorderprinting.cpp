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
void deletedupicate(Node* head){
    Node * curr_node = head;
    while(curr_node != NULL){
        while(curr_node->next != NULL   &&   curr_node->val == curr_node->next->val){
            Node* temp = curr_node->next;
            curr_node->next = curr_node->next->next;
            free(temp);
        }
        curr_node = curr_node->next;
    }
}
void reverseprint(Node* head){
    if(head == NULL) return ;
    reverseprint(head->next);
    cout<<head->val<<"->";

}
int main(){
    Linkedlist ll;
    ll.InsertAtTail(1);
    ll.InsertAtTail(2);
    ll.InsertAtTail(2);
    ll.InsertAtTail(3);
    ll.InsertAtTail(3);
    ll.display();
    
    deletedupicate(ll.head);
    ll.display();

    reverseprint(ll.head);
    cout<<"NULL"<<endl;


    return 0;
}