#include <vector>
using namespace std;
/*
https://leetcode.com/problems/combination-sum
39. Combination Sum
*/


class Solution {
public:
    void backtracking(vector<int>&candidate, vector<int>& current_vec, int start, int end, int remain, vector<vector<int>>& res);

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> current_vec;
        backtracking(candidates, current_vec, 0, candidates.size()-1, target, res);
        return res;
    }
};

void Solution::backtracking(vector<int>&candidate, vector<int>& current_vec, int start, int end, int remain, vector<vector<int>>& res){
    /*for(auto tmp: current_vec){
        cout<<tmp<<" ";
    }
    cout<<endl;*/
    if(remain < 0){
        return;
    }
    else if(remain == 0){
        res.push_back(current_vec);
        return;
    }
    else if(start > end) {
        return;
    }
    else{
        for(int i=start; i<=end;i++){
            current_vec.push_back(candidate[i]);
            backtracking(candidate, current_vec, i, end, remain-candidate[i], res);
            current_vec.pop_back();
        }
    }
}