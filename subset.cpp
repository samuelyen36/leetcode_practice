#include <vector>
using namespace std;

class Solution {

private:
    void backtracking(vector<vector<int>>&, int, int, vector<int>&, vector<int>& );

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        backtracking(res,0, nums.size()-1, nums, cur);
        return res;
    }
};

void Solution::backtracking(vector<vector<int>>& res, int start, int end, vector<int>& nums, vector<int>& cur){
    res.push_back(cur);
    if(start>end){
        return;
    }
    else{
        for(int i=start; i<=end; i++){
            cur.push_back(nums[i]);
            backtracking(res, i+1, end, nums, cur);
            cur.pop_back();
        }
    }
}
