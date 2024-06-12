#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check_row(vector<vector<char>> &board,int p, int q, char c){    // p -> rows : q -> columns
        for(int i=0; i<9; i++){
            if(board[p][i] == c){
                return false;
            }
        }   
        return true;
    }

    bool check_col(vector<vector<char>> &board,int p, int q, char c){    // p -> rows : q -> columns
        for(int i=0; i<9; i++){
            if(board[i][q] == c){
                return false;
            }
        }   
        return true;
    }

    bool check_sqr(vector<vector<char>> &board, int p, int q, char c){   // p -> rows : q -> columns
        int m = p%3;
        int n = q%3;
        for(int i = p-m; i<p-m+3; i++){
            for(int j = q-n; j<q-n+3; j++){
                if(board[i][j] == c){
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    char c = board[i][j];
                    board[i][j] = '.';      // To avoid self check
                    if(!(check_row(board, i, j, c) && check_col(board, i, j, c) && check_sqr(board, i, j, c))){
                        return false;
                    }
                    board[i][j] = c;
                }
            }
        }
        return true;
    }
};

int main(){

    return 0;
}