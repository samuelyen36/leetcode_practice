#include <vector>
using namespace std;
/*
130. Surrounded Regions
https://leetcode.com/problems/surrounded-regions/
*/
class Solution {
private:
    void dfs(vector<vector<char>>& board,int i, int j, int m, int n);
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<n; i++){         //search first and last row
            if(board[0][i] == 'O'){
                this->dfs(board,0, i, m, n);
            }
            if(board[m-1][i] == 'O'){
                this->dfs(board,m-1, i, m, n);
            }
        }
        for(int i=0; i<m; i++){         //search first and last col
            if(board[i][0] == 'O'){
                this->dfs(board, i, 0, m, n);
            }
            if(board[i][n-1] == 'O'){
                this->dfs(board, i, n-1, m, n);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
};

void Solution::dfs(vector<vector<char>>& board,int i, int j, int m, int n){
    if(i<0 || j<0 || i>=m || j>=n){
        return;
    }

    if(board[i][j] != 'O'){     //not what we want, that is, O
        return;
    }
    else{                       //the content is O
        board[i][j] = '#';      //flip 'O' to '#'
        dfs(board, i+1, j, m, n);
        dfs(board, i, j+1, m, n);
        dfs(board, i-1, j, m, n);
        dfs(board, i, j-1, m, n);
    }
}