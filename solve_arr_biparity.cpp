#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int len = nums.size();
        int i=0, j=1;   //index for odd and even number

        for(; i<len && j<len;){
            int flg=1;
            if(nums[i]%2 == 0){
                i+=2;
                flg = flg&0;
            }
            if(nums[j]%2 == 1){
                j+=2;
                flg = flg&0;
            }
            if(flg){        //either i is even nor j is odd
                swap(nums[i],nums[j]);
            }
        }
        return nums;

    }
};