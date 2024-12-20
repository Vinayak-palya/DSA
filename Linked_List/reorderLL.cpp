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

Node* reorderLL(Node* & head){


    // can check if the 
    //finding the middlelement
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

    }

    // now slow is pointing to the next element
    // 2. separate the LL and separate the next half
    Node* curr = slow->next;
    slow->next = NULL;
    Node* prev = slow;
    while(curr){
        Node* nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;

    }
    //3. merging the two haklf of the ll
    Node* ptr1 = head;//linked list 1st half
    Node* ptr2 = prev;//linked list 2nd half
    while(ptr1 != ptr2){
        Node* temp = ptr1->next;
        ptr1->next = ptr2;
        ptr1 = ptr2;
        ptr2 = temp;
    }
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
    ll.InsertAtTail(6);
    ll.display();

    ll.head = reorderLL(ll.head);
    ll.display();
    
   
   
    
    return 0;
}