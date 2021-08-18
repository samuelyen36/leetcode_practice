/*
https://leetcode.com/problems/kth-largest-element-in-an-array
215. Kth Largest Element in an Array
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::sort(nums.begin(),nums.end() , std::greater<int>());
        return nums[k-1];
    }
};