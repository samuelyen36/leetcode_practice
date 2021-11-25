#include <vector>
using namespace std;
/*
https://leetcode.com/problems/interval-list-intersections/
986. Interval List Intersections
*/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int len_1 = firstList.size();
        int len_2 = secondList.size();
        int idx_1=0, idx_2=0;
        while(idx_1<len_1 && idx_2<len_2){
            auto int_1 = firstList[idx_1], int_2 = secondList[idx_2];
            if(int_1[1] < int_2[0] || int_1[0] > int_2[1]){     //not overlap

            }
            else{
                vector<int> interval;
                interval.push_back(max(int_1[0], int_2[0]));
                interval.push_back(min(int_1[1], int_2[1]));
                res.push_back(interval);
            }
            if(int_1[1]<int_2[1]){
                idx_1++;
            }
            else{
                idx_2++;
            }
        }
        return res;
    }
};