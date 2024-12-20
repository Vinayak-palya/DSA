#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int newx , int newy , vector<vector<bool> > &visited , vector<vector<int> > & arr , int n){
    if((newx >= 0 && newx < n) && (newy < n && newy >= 0) && (visited[newx][newy] != 1) && (arr[newx][newy] == 1)){
        return true;
    }
    return false;
}
void solve(int x , int y , vector<vector<int> > & arr ,  int n, vector<vector<bool> > &vis , string path , vector<string > &ans){
    // base case
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return ;
    }
    //  4 movements D,L,R,U
    // down
    if(isSafe(x+1 , y , vis , arr , n)){
        vis[x][y] = 1;
        string res = path + "D";
        solve(x+ 1 , y ,arr , n , vis , res , ans);
        vis[x][y] = 0;
    }
    // left
    if(isSafe(x , y - 1, vis , arr , n)){
        vis[x][y] = 1;
        string res = path + "L";
        solve(x , y  - 1,arr , n , vis , res , ans);
        vis[x][y] = 0;
    }
    // right
    if(isSafe(x , y+1 , vis , arr , n)){
        vis[x][y] = 1;
        string res = path + "R";
        solve(x , y +1,arr , n , vis , res , ans);
        vis[x][y] = 0;
    }
    
    // up
    if(isSafe(x - 1 , y , vis , arr , n)){
        vis[x][y] = 1;
        string res = path + "U";
        solve(x- 1 , y ,arr , n , vis , res , ans);
        vis[x][y] = 0;
    }
}
vector<string> searchMaze(vector<vector<int> > & arr , int n){
    string path = "";
    vector<string> ans;
    vector<vector< bool> > visited(n , vector<bool> (n , 0));
    if(arr[0][0] == 0){
        return ans;
    }
    solve(0 , 0 ,arr , n , visited , path , ans);
    return ans;
}
int main(){
    return 0;
}