#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long int sum_of_arr=1;
        long long int with_zero=1;      //if the array consist of zero, then don't multiply it and store the rest product to here.
        int zero_count=0;       //count how many elements are zero
        vector<int> res;
        for(auto i: nums){
            if(i==0){
                sum_of_arr = 0;
                zero_count++;
                continue;
            }
            else{
            sum_of_arr *= i;
            with_zero *= i;
            }
        }
        for(auto k: nums){
            if(k==0 && zero_count == 1){
                res.push_back(with_zero);
            }
            else if(k==0 && zero_count > 1){
                res.push_back(0);
            }
            else{
                res.push_back(sum_of_arr/k);
            }
        }
        return res;
    }
};