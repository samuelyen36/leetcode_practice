#include <string>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;
/*
451. Sort Characters By Frequency
https://leetcode.com/problems/sort-characters-by-frequency/
*/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        priority_queue<pair<int, char> > pq;
        string res;
        for(char c: s){
            freq[c]++;
        }
        for(auto it: freq){                     //push item in freq into priority queue
            pq.push(make_pair(it.second, it.first));
        }

        while (!pq.empty()){
            pair<int, char> tmp = pq.top();
            for(int i=0; i<tmp.first; i++){
                res+=tmp.second;
            }
            pq.pop();
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout<<sol.frequencySort("AABBBcddddd")<<endl;

}