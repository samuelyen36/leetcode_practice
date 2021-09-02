#include <vector>
using namespace std;

class Solution {
private:
    void backtracking(vector<vector<int>> &, int, vector<int>&, int);
    vector<int> tmp;
public:
    vector<vector<int>> combine(int n, int k) {
        for(int i=1; i<=n; i++){
            this->tmp.push_back(i);
        }
        vector<vector<int>> res;
        vector<int> vec;
        backtracking(res, k, vec, 0);
        return res;
    }
};

void Solution::backtracking(vector<vector<int>>& res, int remain, vector<int>& vec, int idx){
    if(remain==0){
        res.push_back(vec);
        return;
    }
    else{
        for(int k=idx; k< (this->tmp.size()); k++){
            vec.push_back(this->tmp[k]);
            this->backtracking(res, remain-1, vec, k+1);
            vec.pop_back();
        }
        return;
    }
}