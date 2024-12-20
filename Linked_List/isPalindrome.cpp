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

bool isPalindrome(Node* &head){
//find middle element
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

    }
    //now slow is pointing to middle element
    // 2. break the LL in the middle

    Node* curr = slow->next;
    Node* prev = slow;

    slow->next = NULL;
    //3.reversing the LL
    while(curr){
        Node* nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }
    Node* head2 = prev;
    Node* head1 = head;
    //second half <= firsthalf
    while(head2){
        if(head1->val != head2->val) return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}
int main()
{
    Linkedlist ll;
    ll.InsertAtTail(1);
    ll.InsertAtTail(2);
    ll.InsertAtTail(3);
    ll.InsertAtTail(4);
    // ll.InsertAtTail(4);
    ll.InsertAtTail(3);
    ll.InsertAtTail(2);
    ll.InsertAtTail(1);

    
   cout<<isPalindrome(ll.head)<<"\n";

    
    return 0;
}