#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int start = 0, end = len-1;
        int res;

        while(start != end){
            if(end - start == 1){
                return min(nums[start], nums[end]);
            }
            else if(nums[start] < nums[end]){
                return nums[start];
            }
            else{
                int mid = start + ((end-start)/2);
                if(nums[mid] > nums[start]){        //ans we want is in the RHS
                    start = mid;
                    continue;
                }
                else{
                    end = mid;
                    continue;
                }
            }
        }
        return nums[start];
    }
};