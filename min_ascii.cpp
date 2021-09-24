#include <string>
#include <vector>
using namespace std;
/*
712. Minimum ASCII Delete Sum for Two Strings
https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/discuss/108828/C%2B%2B-DP-with-explanation
*/
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> vec(m+1, vector<int> (n+1, 0));     //dp[i][j] is the cost for s1.substr(0,i) and s2.substr(0, j). Note s1[i], s2[j] not included in the substring.
        for(int i=1; i<=m; i++){
            vec[i][0] = vec[i-1][0] + s1[i-1];
        }
        for(int i=1; i<=n; i++){
            vec[0][i] = vec[0][i-1] + s2[i-1];
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]){
                    vec[i][j] = vec[i-1][j-1];
                }
                else{
                    vec[i][j] = min(vec[i-1][j] + s1[i-1], vec[i][j-1] + s2[j-1]);
                }
            }
        }
        return vec[m][n];
    }
};