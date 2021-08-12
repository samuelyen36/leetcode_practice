#include <vector>
#include <map>
/*
260. Single Number III
https://leetcode.com/problems/single-number-iii/
*/
class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        std::map<int, int> map_appear;
        std::vector<int> res;
        for(auto it = nums.begin(); it!=nums.end(); it++){
            //*it -> value of current item
            auto _f = map_appear.find((*it));
            if(_f != map_appear.end()){     //already exist in the map
                _f->second = 2;
            }
            else{                           //not exist in the map
                map_appear[(*it)] = 1;                   
            }
        }

        for(auto it = map_appear.begin(); it != map_appear.end(); it++){
            if(it->second == 1){
                res.push_back(it->first);
            }
        }
        return res;
    }
};