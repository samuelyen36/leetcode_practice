/*
https://leetcode.com/problems/house-robber/
198. House Robber
*/
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        else if(nums.size() == 1)   return nums[0];
        else if(nums.size() == 2)   return max(nums[0],nums[1]);

        int* arr = new int[nums.size()];
        for(auto i=0; i<nums.size(); i++){
            arr[i] = 0;
        }
        arr[0] = nums[0];
        arr[1] = max(nums[0], nums[1]);

        for(auto i=2; i<nums.size(); i++){
            arr[i] = max(arr[i-2] + nums[i], arr[i-1]);
            //cout<<i<<"\t"<<arr[i]<<"\n";
        }
        int res = arr[nums.size()-1];
        delete []arr;
        return res;
    }
};