
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void recursive_find(int start, int end, int remain,vector<int> candidate, vector<vector<int>>& res);


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> can;
        recursive_find(1,k,n,can,res);
        return res;
    }
};


void Solution::recursive_find(int start, int end, int remain,vector<int> candidate, vector<vector<int>>& res){
    if(remain == 0 && end==0){
        //cout<<"push to res\n";
        res.push_back(candidate);
    }
    else{
        for(int i=start; i<=remain && i<=10-end; i++){
            //cout<<"push i: "<<i<<endl;
            candidate.push_back(i);
            recursive_find(i+1, end-1, remain-i,candidate, res);
            candidate.pop_back();
            //cout<<"pop i: "<<i<<endl;
        }
    }
}