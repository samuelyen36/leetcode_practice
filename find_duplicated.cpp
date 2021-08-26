#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        unordered_set<int> _set;
        for(auto i: nums){
            if(_set.count(i) == 0){
                _set.insert(i);
            }
            else{
                return i;
            }
        }

    }
};