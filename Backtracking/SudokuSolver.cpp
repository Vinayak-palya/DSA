#include<iostream>
#include<vector>
using namespace std;
bool isSafe(vector<vector<int> > & board , int val , int row ,int col){
    int n = board.size();
    for(int i = 0;i < n;i++)
    {
        //row check
        if(board[row][i] == val)
        return false;
        //col check
        if(board[i][col] == val)
            return false;
            // 3* 3 matrix check
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val){
                return false;
            }

    }
    return true;
}
bool solve(vector<vector <int> > &board ){
    int n = board.size();
    for(int row = 0;row < n;row++){
        for(int col = 0;col < n;col++){
            if(board[row][col] == 0){
                for(int val = 1;val <= 9;val++){
                    if(isSafe(board , val , row , col)){
                        board[row][col] = val;
                        // recursion
                        bool furtherSolution = solve(board);
                        if(furtherSolution){
                            return true;
                        }
                        else{// backtrack
                            board[row][col] = 0;
                        } 
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void sudokuSolver(vector<vector<int> > & board){
    int n = board.size();
    
}
int main(){

    return 0;
}