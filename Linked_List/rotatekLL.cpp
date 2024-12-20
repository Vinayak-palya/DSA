#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int num)
    {
        val = num;
        next = NULL;
    }
};
class Linkedlist
{
public:
    Node *head;
    Linkedlist()
    {
        head = NULL;
    }
    void InsertAtTail(int value)
    {

        Node *new_node = new Node(value);

        if (head == NULL)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

Node* rotateByk(Node* &head,int k){
    //find length of the LL
    int n = 0;

    //find tail node;
    Node* tail = head;
    while(tail->next){
        n++;
        tail = tail->next;

    }
    n++;
    k = k % n;
    if(k == 0){
        return head;
    }
    tail->next = head;
    // traverse through n-k nodes;
    Node* temp = head;
    for(int i = 1;i < n-k;i++){
        temp = temp->next;
    }
    // temp is pointing to n-k th node
    Node* newhead = temp->next;
    temp->next = NULL;

    return newhead;
}



int main()
{
    Linkedlist ll;
    ll.InsertAtTail(1);
    ll.InsertAtTail(2);
    ll.InsertAtTail(3);
    ll.InsertAtTail(4);
    ll.InsertAtTail(5);
    ll.InsertAtTail(6);
    ll.display();

    ll.head = rotateByk(ll.head,3);
    ll.display();
    
   
   
    
    return 0;
}