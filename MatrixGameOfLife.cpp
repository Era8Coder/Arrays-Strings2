#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> delta_x = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> delta_y = {-1, 0, 1, -1, 1, -1, 0, 1};

    bool isValidPoint(int x, int y, int rows, int cols) {
        return (x >= 0 && x < rows && y >= 0 && y < cols);
    }

    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, 0));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                int cnt_of_one = 0;
                for(int k = 0; k < 8; k++) {
                    int newX = i + delta_x[k];
                    int newY = j + delta_y[k];
                    if(isValidPoint(newX, newY, rows, cols) && board[newX][newY] == 1) {
                        cnt_of_one += 1;
                    }
                }
                if(board[i][j] == 1 && cnt_of_one < 2) {
                    ans[i][j] = 0;
                } else if(board[i][j] == 1 && (cnt_of_one == 2 || cnt_of_one == 3)) {
                    ans[i][j] = 1;
                } else if(board[i][j] == 1 && cnt_of_one > 3) {
                    ans[i][j] = 0;
                } else if(board[i][j] == 0 && cnt_of_one == 3) {
                    ans[i][j] = 1;
                }
            }
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                board[i][j] = ans[i][j];
            }
        }
    }
};

int main(){

    return 0;
}