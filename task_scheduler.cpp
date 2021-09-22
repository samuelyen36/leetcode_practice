#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> _map;
        int most_freq=0;            //count what's the largest occurance
        int ans;
        for(auto c: tasks){
            _map[c]++;
            most_freq = max(most_freq, _map[c]);
        }
        ans = (most_freq-1) * (n+1);        //count the cycles we need before the last occurance.
        for(auto c: _map){
            if(c.second == most_freq){
                ans++;
            }
        }
        ans = max((int)tasks.size(), ans);
        return ans;
    }
};