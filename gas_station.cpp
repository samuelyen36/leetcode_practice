#include <vector>
using namespace std;
/*
134. Gas Station
https://leetcode.com/problems/gas-station/
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        int total=0, current=0, start=0;
        for(int i=0; i<len; i++){   
            auto delta = gas[i] - cost[i];      //amount we gain in this step
            current += delta;
            total += delta;
            if(current < 0){
                start = i+1;
                current=0;
            }
        }
        return total<0 ? -1 : start;
    }
};