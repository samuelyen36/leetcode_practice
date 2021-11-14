#include <vector>
using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int startval = 0;
        int sum=0;
        for(auto i: nums){
            sum += i;
            startval = min(startval, sum);
        }
        return startval*-1+1;
    }
};