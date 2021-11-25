#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = 0;
        int global_max = INT_MIN;
        vector<int> res;
        for(auto i: nums){
            current_sum+=i;
            res.push_back(current_sum);
            if(current_sum>global_max){
                global_max = current_sum;
            }
            if(current_sum<0){
                current_sum=0;
            }
        }
        return global_max;
    }
};