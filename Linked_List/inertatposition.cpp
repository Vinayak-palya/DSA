#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int data){
        val = data;
        next = NULL;
    }
};
void InsertAtHead(Node* &head,int val){
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}
// void InsertAtTail(Node* &head,int val){

//     Node* new_node = new Node(val);
//     Node* temp = head;
//     while(temp->next != NULL){
//         temp = temp->next;

//     }
//     temp->next = new_node;
// }
void InsertAtposition(Node* head,int val,int pos){
    if(pos == 0){
        InsertAtHead(head,val);
        return ;
    }
    Node* new_node = new Node(val);
    Node* temp = head;
    int curr_pos = 0;
    while(curr_pos != pos -1){
        temp = temp->next;
        curr_pos++;
    }
    //temp is pointing to the node at the position - 1
    new_node->next = temp->next;
    temp->next = new_node;
}

void display(Node* head){


    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

}

void InsertAtTail(Node* &head,int val){

    Node* new_node = new Node(val);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;

    }
    temp->next = new_node;
}


void updateatkTHposition(Node* &head,int k,int val){
    Node* temp = head;
    int curr_pos = 0;
    while(curr_pos != k){
        temp = temp->next;
        curr_pos ++;
    }
    temp->val = val;
}

int main(){
Node* head = NULL;
    InsertAtHead(head,2);
    display(head);
    InsertAtHead(head,1);
    display(head);
    InsertAtTail(head,3);
    display(head);
    InsertAtposition(head,4,1);
    updateatkTHposition(head,2,5);
    
    display(head);
    return 0;
}