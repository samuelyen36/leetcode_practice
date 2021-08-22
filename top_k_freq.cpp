#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

/*
347. Top K Frequent Elements
https://leetcode.com/problems/top-k-frequent-elements/
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> map;
        vector<int> res;
        pair<int,int> tmp;

        for(auto i:nums){
            map[i]++;
        }

        for(auto i: map){
            pq.push(make_pair(i.second, i.first));
        }
        
        for(int i=0; i<k; i++){
            tmp = pq.top();
            pq.pop();
            res.push_back(tmp.second);
        }
        return res;
    }
};