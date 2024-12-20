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

Node* oddEvenLL(Node* &head){
    if(!head) return head;
    Node* evenhead = head->next;
    Node* odd = head;
    Node* even = evenhead;
    while(even &&even->next){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenhead;
    return head;
}


int main()
{
    Linkedlist ll;
    ll.InsertAtTail(1);
    ll.InsertAtTail(2);
    ll.InsertAtTail(3);
    ll.InsertAtTail(4);
    ll.InsertAtTail(5);
    // ll.InsertAtTail(6);
    ll.display();

    ll.head = oddEvenLL(ll.head);
    ll.display();
    
   
   
    
    return 0;
}