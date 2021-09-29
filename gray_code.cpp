#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

class Solution {
private:
    void back_tracking(vector<int>&, int, bitset<32>&);
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        bitset<32> bs;
        this->back_tracking(res, n, bs);
        return res;
    }
};

void Solution::back_tracking(vector<int>& res, int k, bitset<32>& bs){
    if(k==0){
        res.push_back(bs.to_ulong()); //push result into vector
    }
    else{
        back_tracking(res, k-1, bs);
        bs.flip(k-1);
        back_tracking(res, k-1, bs);
    }
    return;
}

int main(int argc, char** argv){
    int n = atoi(argv[1]);
    Solution sol;
    for(auto i: sol.grayCode(n)){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}