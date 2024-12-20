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

bool detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    if(!head){
        return false;

    }
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast){
            cout<<slow->val<<"\n";
            return true;

        }
    }
    return false;
}
void removecycle(Node* &head){
Node* slow  = head;
Node* fast = head;
do
{
slow = slow->next;
fast = fast->next->next;

}while(slow != fast);

fast = head;
while(slow->next != fast->next){
    slow = slow->next;
    fast = fast->next;
}
slow->next = NULL;
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
    ll.InsertAtTail(7);
    ll.InsertAtTail(8);

    ll.head->next->next->next->next->next->next->next->next = ll.head->next->next;
    cout<<detectCycle(ll.head)<<endl;
    removecycle(ll.head);
    cout<< "After removing cycle" <<detectCycle(ll.head)<<endl;
    ll.display();

    
    return 0;
}