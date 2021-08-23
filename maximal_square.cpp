#include <vector>
#include <iostream>
using namespace std;
/*
https://leetcode.com/problems/maximal-square/
221. Maximal Square
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));        //initialize DP array
        int _max=-1;
        for(int i = 0; i < matrix.size(); i++){
            for(int j=0; j< matrix[0].size(); j++){
                if(j==0 || i==0){
                    dp[i][j] = matrix[i][j] - '0';      //the size row and coloum will be initialized to zero
                }
                else if(matrix[i][j] == '0'){
                    dp[i][j] = matrix[i][j] - '0';          //'0' can't be merge into a square
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
                _max = (dp[i][j]>_max) ? dp[i][j] :_max;
            }
        }
        /*for(int i = 0; i < matrix.size(); i++){
            for(int j=0; j< matrix[0].size(); j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return _max*_max;
    }
};
/*
int main(){

}*/