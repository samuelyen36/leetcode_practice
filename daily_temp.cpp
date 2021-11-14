#include <vector>
#include <utility>
using namespace std;
/*
739. Daily Temperatures
https://leetcode.com/problems/daily-temperatures/
https://bit.ly/31R9CXn
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        for(int i=temperatures.size()-2; i>=0; i--){
            if(temperatures[i+1] > temperatures[i]){        //adjecent day gets warmer
                res[i] = 1;
            }
            else if(temperatures[i] > temperatures[i+1] && res[i+1]==0){        //not possible to get warmer in the future
                res[i] = 0;
            }
            else{
                int idx=i+1;
                while(idx < temperatures.size()){
                    if(res[idx] == 0){      //not possible to get warmer
                       break;
                   }
                   idx = idx+res[idx];      //goes to the future to peek where's gonna be higher temperature
                   if(temperatures[idx] > temperatures[i]){
                       res[i] = idx-i;
                       break;
                   }
                }
            }
        }

        return res;
    }
};