#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    int row;
    int coln;
    node(int data , int row , int coln){
        this->data = data;
        this->row = row;
        this->coln = coln;
    }
};
class Compare{
    public:
    bool operator()(node* a , node* b){
        return a->data > b->data;
    }
};
int kSortedList(vector<vector<int> > &a , int k,int n){
    int mini = INT_MAX;
    int maxi = INT_MIN;
    priority_queue<node* , vector<node* > , Compare> minHeap;
    for(int i = 0;i < k;i++){
        int element = a[i][0];
        mini = min(mini , element);
        maxi = max(maxi , element);
        minHeap.push(new node(element , i , 0));
    }
    int start = mini;
    int end = maxi;
    while(!minHeap.empty()){
        node* temp = minHeap.top();
        minHeap.pop();
        mini = temp->data;
        if((end - start) > (maxi - mini)){
            start = maxi;
            end = mini;
        }
        if(temp->coln + 1 < n){
            maxi = max(maxi , a[temp->row][temp->coln + 1]);
            minHeap.push(new node(a[temp->row][temp->coln + 1] , temp->row , temp->coln+1));
        }
        else{
            break;
        }

    }
    return (end - start + 1);

}
int main(){

    return 0;
}