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
    bool IsBalanced(node *);
    pair<bool , int> IsBalancedopt(node *);
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

bool node :: IsBalanced(node * root)
{ // time complexity --> O(N^2);

    if (root == NULL)
        return true;
    bool left = IsBalanced(root->left);
    bool right = IsBalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    if (left && right && diff)
    {
        return true;
    }

    return false;
}

pair<bool, int> node ::IsBalancedopt(node *root)
{ // time compl --> O(N);
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = IsBalancedopt(root->left);
    pair<bool, int> right = IsBalancedopt(root->right);
    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <= 1;
    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

bool IsIdentical(node *r1, node *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if ((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL))
    {
        return false;
    }
    bool left = IsIdentical(r1->left, r2->left);
    bool right = IsIdentical(r1->right, r2->right);
    bool value = r1->data == r2->data;
    if (left && right && value)
    {
        return true;
    }
    else
    {
        return false; // time compl--> O(N);
    }
}

void TraverseLeft(node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;
    ans.push_back(root->data);
    if (root->left != NULL)
    {
        TraverseLeft(root->left, ans);
    }
    else
    {
        TraverseLeft(root->right, ans);
    }
}

void traverseleaf(node *root, vector<int> &ans)
{
    if (root == NULL)
        return ;
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    traverseleaf(root->left, ans);
    traverseleaf(root->right, ans);
}

void traverseRight(node *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    if (root->right)
        traverseRight(root->right,ans);
    else
    {
        traverseRight(root->right,ans);
    }
    ans.push_back(root->data);
}
vector<int> boundary(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data);

    // left part print / store
    TraverseLeft(root->left, ans);

    // traverse leaf nodes

    // left subtree
    traverseleaf(root->left, ans);
    // right subtree
    traverseleaf(root->right, ans);

    // traverse right part
    traverseRight(root->right, ans);
    return ans;
}

vector<int> verticalOrder(node *root)
{
    map<int, map<int, vector<int> > > nodes;
    queue<pair<node *, pair<int, int> > > q;
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    q.push(make_pair(root , make_pair(0,0)));
    while (!q.empty())
    {
        pair<node *, pair<int, int> > temp = q.front();
        q.pop();
        node *frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;
        nodes[hd][lvl].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}


vector<int> Topview(node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
        map<int , int> topNode;
        queue<pair<node* ,int> > q;
        q.push(make_pair(root , 0));

        while(!q.empty()){
            pair<node* ,int> temp = q.front();
            node* front = temp.first;
            int hd = temp.second;
            // if one value is present for the one horizontal distance then do nothing
            if(topNode.find(hd) == topNode.end())
            topNode[hd] = front->data;
            if(front->left){
                q.push(make_pair(front->left , hd - 1));
            }
            if(front->right){
                q.push(make_pair(front , hd+1));
            }



        }
        for(auto i: topNode){
            ans.push_back(i.second);
        }
    }
    return ans;
}



vector<int> bottomView(node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
        map<int , int> topNode;
        queue<pair<node* ,int> > q;
        q.push(make_pair(root , 0));
        while(!q.empty()){
            pair<node* ,int> temp = q.front();
            node* front = temp.first;
            int hd = temp.second;
            // if one value is present for the one horizontal distance then do nothing
            
            topNode[hd] = front->data;
            if(front->left){
                q.push(make_pair(front->left , hd - 1));
            }
            if(front->right){
                q.push(make_pair(front , hd+1));
            }



        }
        for(auto i: topNode){
            ans.push_back(i.second);
        }
    }
    return ans;

}



void solve(node* root , vector<int> &ans,int lvl){
if(root == NULL) return ;
if(lvl == ans.size())  ans.push_back(root->data);
solve(root->left,ans,lvl+1);
solve(root->right, ans,lvl+1);
}


vector<int> leftView(node* root){
    vector<int> ans;
    solve(root , ans , 0);
    return ans;
}


void solvesecond(node* root, vector<int> ans , int lvl){
    if(root == NULL) return ;
if(lvl == ans.size())  ans.push_back(root->data);
solve(root->right, ans,lvl+1);
solve(root->left,ans,lvl+1);
}


vector<int> rightView(node* root){
    vector<int> ans;
    solvesecond(root , ans , 0);
    return ans;
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