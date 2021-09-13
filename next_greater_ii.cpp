#include <vector>
#include <stack>
#include <iostream>
using namespace std;
/*
503. Next Greater Element II
https://leetcode.com/problems/next-greater-element-ii/
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> st;

        for(int i=0; i<nums.size()*2; i++){
            int cur_num = nums[i%(nums.size())];
            while(st.empty()==false && nums[st.top()] < cur_num){       //meet greater element
                res[st.top()] = cur_num;
                st.pop();
            }
            if(i < nums.size()){
                st.push(i);
            }
        }
        return res;
    }
};



int main(){
    Solution sol;
    vector<int> vec = {1,2,3,4,5,7,8};
    auto res = sol.nextGreaterElements(vec);
    for(auto k: res){
        cout<<k<<"\t";
    }
    cout<<endl;
}