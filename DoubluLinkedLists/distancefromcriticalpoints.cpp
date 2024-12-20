#include<iostream>
#include<vector>
using namespace std;


class Node{
    public:
    int val;
    Node* prev;
    Node* next;
    Node(int num){
        val = num;
        prev = NULL;
        next = NULL;

    }


};
class DoublyLinkedList{

    public:
    Node* head;
    Node* tail;

    DoublyLinkedList(){
        head = NULL;
        tail = NULL;

    }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<"<->";
            temp = temp->next;
        }cout<< "NULL" <<endl;
    }
    void InsertAtStart(int val){
        Node* new_node = new Node(val);
        if(!head){
            head = new_node;
            tail = new_node;
            return ;
        }
        new_node->next = head;
        new_node->prev = NULL;
        head->prev = new_node;
        head = new_node;

    }
    void InsertAtEnd(int val){
        Node* new_node = new Node(val);
        if(tail == NULL){
            head = new_node;
            tail = new_node;
            return;

        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return ;
    }
    void InsertAtPosition(int val,int k){
        // assuming that k is less than eqaul to length of the linked list
        Node* temp = head;
        int count = 1;
        while(count < (k-1)){
            temp = temp->next;
            count++;


        }
        Node* new_node =new Node(val);
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        new_node->next->prev = new_node;
        return ;

    }
    void deleteAtStart(){
        if(head == NULL){
            return ;

        }
        Node* temp = head;
        head = head->next;
        if(head != NULL){
            head->prev = NULL;
        }
        else{
            tail = NULL;
        }
        

        free(temp);
    }
    void deleteAtEnd(){
        if(head == NULL){
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if(tail == NULL){
            head = NULL;
        }
        else{
            tail->next = NULL;
        }
        free(temp);
        return;
    }
    void deleteAtKthPosition(int k){
        //assuming k is lessthan or equal to length of dll;
        Node* temp = head;
        int counter = 1;
        while(counter < k){
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

};


void reverseDLL(Node* &head, Node* &tail)
{
    Node* currptr = head;
    while (currptr)
    {
        Node *nextptr = currptr->next;
        currptr->next = currptr->prev;
        currptr->prev = nextptr;
        currptr = nextptr;
    }
    Node* temp = head;
    head = tail;
    tail = temp;
}
bool isCriticalPoint(Node* currNode){
    if(currNode->prev->val < currNode->val && currNode->next->val < currNode->val){
        return true;
    }
    if(currNode->prev->val > currNode->val && currNode->next->val > currNode->val){
        return true;
    }
    return false;
}

vector<int> distanceBetweenCriticalPoints(Node* head,Node* tail){
    vector<int> ans(2,INT_MAX);
    int first = -1,last = -1;
    Node* currNode = tail->prev;
    if(currNode==NULL){
        ans[0] = ans[1] = -1;
        return ans;
    }
    int currposition = 0;
    while(currNode->prev!=NULL){
        if(isCriticalPoint(currNode)){
            if(first == -1){
                first = last = currposition;
            }
            else{
                ans[0] = min(ans[0],currposition - last);
                ans[1] = currposition - first;
                last = currposition;

            }
        }
        currposition++;
        currNode = currNode->prev;
    }
    if(ans[0] == INT_MAX){
        ans[0] = ans[1] = -1;
    }
    return ans;
}

int main(){
    DoublyLinkedList dll;

   
    dll.InsertAtEnd(1);
    dll.InsertAtEnd(5);
    dll.InsertAtEnd(2);
    dll.InsertAtEnd(6);
    dll.InsertAtEnd(3);
    dll.display();

    vector<int> ans = distanceBetweenCriticalPoints(dll.head,dll.tail);

    cout<<ans[0]<<"-"<<ans[1]<<endl;
    return 0;
}