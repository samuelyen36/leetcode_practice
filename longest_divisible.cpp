#include <vector>
#include <algorithm>
using namespace std;
/*
https://leetcode.com/problems/largest-divisible-subset/
368. Largest Divisible Subset
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> trace(n, -1);
        vector<int> res;
        int maxidx=-1;
        int _max=-1;
        

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        trace[i] = j;
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++){
            if(dp[i] > _max){
                _max = dp[i];
                maxidx = i;
            }
        }

        while(maxidx != -1) {
            res.push_back(nums[maxidx]);
            maxidx = trace[maxidx];
        }        
        return res;
    }
};