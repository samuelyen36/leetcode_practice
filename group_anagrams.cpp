#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map < string, vector <string>> map;
        vector<vector<string>> res;
        
        for(auto it = strs.begin(); it != strs.end(); it++){
            auto tmp = *it;
            sort((tmp).begin(),(tmp).end() );       //sort a string
            map[(tmp)].push_back((*it));    
        }

        for(auto it = map.begin(); it != map.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};