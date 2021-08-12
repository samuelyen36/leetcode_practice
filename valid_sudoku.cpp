/*
36. Valid Sudoku
https://leetcode.com/problems/valid-sudoku/
*/

#include <vector>
using namespace std;
class Solution {
public:
    bool check_block(vector<vector<char>>& board);
    bool check_col(vector<vector<char>>& board);
    bool check_row(vector<vector<char>>& board);

    bool isValidSudoku(vector<vector<char>>& board) {
        return(check_block(board) && check_col(board) && check_row(board));
    }
};

bool Solution::check_block(vector<vector<char>>& board){
    for(int i=0; i<3; i++){         
        for(int j=0; j<3; j++){     //outer block
            int arr[10]={0};
            for(int x=0; x<3; x++){
                for(int y=0; y<3; y++){
                    if(board[i*3+x][j*3+y]!='.'){       //this position is a digit
                        if(arr[ board[i*3+x][j*3+y]-'0' ] >= 1){
                            return false;
                        } 
                        else{
                            arr[ board[i*3+x][j*3+y]-'0' ]++;
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool Solution::check_col(vector<vector<char>>& board){
    for(int i=0; i<9; i++){
        int arr[10] = {0};
        for(int k=0; k<9; k++){
            if(board[i][k] != '.'){
                if(arr[ board[i][k]-'0' ] >= 1){
                    return false;
                }
                else{
                    arr[ board[i][k]-'0' ]++;
                }
            }
        }
    }
    return true;
}


bool Solution::check_row(vector<vector<char>>& board){
    for(int i=0; i<9; i++){
        int arr[10] = {0};
        for(int k=0; k<9; k++){
            if(board[k][i] != '.'){
                if(arr[ board[k][i]-'0' ] >= 1){
                    return false;
                }
                else{
                    arr[ board[k][i]-'0' ]++;
                }
            }
        }
    }
    return true;
}


int main(void){


    return 0;
}