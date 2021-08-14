#include <vector>
#include <iostream>
using namespace std;
/*
73. Set Matrix Zeroes
https://leetcode.com/problems/set-matrix-zeroes/
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        int flg=0, clean_first_row=0, clean_first_col=0;

        if(row_size == 1){
            for(int k=0; k<col_size; k++){
                if(matrix[0][k] == 0){
                    for(int t = 0; t<col_size; t++){
                        matrix[0][t] = 0;
                    }
                    return;
                }
            }
        }
        if(col_size == 1){
            for(int k=0; k<row_size; k++){
                if(matrix[k][0] == 0){
                    for(int t = 0; t<row_size; t++){
                        matrix[t][0] = 0;
                    }
                    return;
                }
            }
        }

        for(int i=0; i<row_size;i++){       //clean 0,0 later
            if(matrix[i][0] == 0){
                flg=1;
                clean_first_col=1;
            }
        }
        for(int j=0; j<col_size; j++){
            if(matrix[0][j] == 0){
                flg=1;
                clean_first_row=1;
            }
        }


        for(int i=1; i<row_size; i++){              //skip the index0, for we'll use it as the indicator
            for(int j=1; j<col_size; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int j=1; j<col_size; j++){
            if(matrix[0][j] == 0){        //clean the
                for(int k=0; k<row_size; k++){
                    matrix[k][j]=0;
                }
            }
        }

        for(int i=1; i<row_size; i++){
            if(matrix[i][0] == 0){
                for(int k=0; k<col_size; k++){
                    matrix[i][k]=0;
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int i=0; i<col_size; i++){
                matrix[0][i]=0;
            }
            for(int j=0; j<row_size; j++){
                matrix[j][0]=0;
            }
        }


        if(clean_first_col){
            for(int i=0; i<row_size;i++){       //clean first row and column
                matrix[i][0] = 0;
            }
        }

        if(clean_first_row){
            for(int i=0; i<col_size;i++){       //clean first row and column
                matrix[0][i] = 0;
            }
        }

        if(flg){
            matrix[0][0] = 0;
        }
        return;
    }
};