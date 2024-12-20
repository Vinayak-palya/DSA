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

class CircularLinkedList{
    public:
    Node* head;
    CircularLinkedList(){
        head = NULL;

    }
    void display(){
        Node* temp = head;
        do{
            cout<<temp->val<<"->";
            temp = temp->next;
        }while(temp!=head);
        cout<<endl;
    }

    void printCircular(){
        Node* temp = head;
        for(int i = 0;i < 15;i++){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
    }
    void InsertAtStart(int val){
    Node* new_node = new Node(val);
    if(head == NULL){
        head = new_node;
        new_node->next = head;
        return ;
    }
    Node* tail = head;
    while(tail->next != head){
        tail = tail->next;
    }
    tail->next = new_node;
    new_node->next = head;
    head = new_node;
}

void insertAtEnd(int val){
    Node* new_node = new Node(val);
    if(head == NULL){
        head = new_node;
        new_node->next = head;
    }
    Node* tail = head;
    while(tail->next != head){
        tail = tail->next;

    }
    tail->next = new_node;
    new_node->next = head;

}
void delteAtStart(){
    if(head == NULL){
        return ;

    }
    Node* temp = head;
    Node*tail = head;
    while(tail->next != head){
        tail = tail->next;
    }
    head = head->next;
    tail->next = head;
    free(temp);
}
void deleteAtEnd(){
    Node* temp = head;
    Node* tail = head;
    if(head == NULL){
        return ;
    }
    while(tail->next->next != head){
        tail = tail->next;
    }
    temp = tail->next;
    tail->next = head;
    free(temp);
}

};



int main(){
    CircularLinkedList cll;
    cll.InsertAtStart(3);
    cll.InsertAtStart(2);
    cll.InsertAtStart(1);
    // cll.display();
    // cll.printCircular();
    cll.insertAtEnd(8);
    // cll.display();
    cll.delteAtStart();
    cll.display();
    // cll.printCircular();

    cll.deleteAtEnd();
    cll.display();
    cll.printCircular();

    return 0;
}