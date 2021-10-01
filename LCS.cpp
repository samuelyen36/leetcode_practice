#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
1143. Longest Common Subsequence
https://leetcode.com/problems/longest-common-subsequence/
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int rows = text1.size()+1, cols = text2.size()+1;       //0~t1size,   0~t2size
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        for(int i=1; i<rows; i++){      //1~t1size-1
            for(int j=1; j<cols; j++){  //1~t2size-1
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[rows-1][cols-1];
    }
};

int main(void){
    Solution sol;
    string _1 = "abcde";
    string _2 = "ace";
    cout<<sol.longestCommonSubsequence(_1, _2)<<endl;
    return 0;
}