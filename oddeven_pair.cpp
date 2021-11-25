#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int start = 0;
        int end = nums.size()-1;
        int mid = (end-start)/2 + start;
        while(mid<=end && mid>=start && start!=end){
            int p_idx = mid^1;
            if(nums[mid] != nums[p_idx]){
                end = mid;
            }
            else{
                start = mid+1;
            }
            mid = (end-start)/2 + start;
        }
        return nums[start];
    }
};