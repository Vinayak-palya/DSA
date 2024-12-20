#include <iostream>
#include <queue>
#include <map>

using namespace std;

/*
time complexity = O(N)
space complexity = O(height);
*/
class node
{
private:
    int height(node *root)
    {
        if (root == NULL)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left, right) + 1;
        return ans;
    }

public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
    
};
node *buildtree(node *root)
{
    cout << "enter the data for the node: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter the data for inserting in left of " << data << "\n";
    root->left = buildtree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {

        node *temp = q.front();

        q.pop();
        if (temp == NULL)
        { // purana level pura traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            { // queue still has some child nodes
                q.push(NULL);
            }
        }
        // q.push(NULL) act as a separator
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}
void solve(node* root , int sum , int length , int &maxLen , int maxSum){
    if(root == NULL){
        if(length > maxLen){
            maxLen = length;

        }
        else if(length == maxLen){
            maxSum = max(sum , maxSum);


        }
        return ;
    }
    sum = sum + root->data;
    solve(root->left , sum , length  + 1, maxLen, maxSum);
    solve(root->right , sum , length + 1,maxLen , maxSum);
    return maxSum;
}

int SumOfLongRootPath(node* root){
    int length = 0;
    int maxlen = 0;
    int sum = 0;
    int maxSum = INT_MIN;

    solve(root , sum ,length,maxlen , maxSum);
    return maxSum;
}



int main()
{
    node *root = NULL;

    // creating a Tree

    root = buildtree(root);

    // level order traversal
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << root->IsBalanced(root) << endl;

    return 0;
}