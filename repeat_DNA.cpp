#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
/*
https://leetcode.com/problems/repeated-dna-sequences/
187. Repeated DNA Sequences
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int last = s.size();
        unordered_set<string> _set,res_set;
        vector<string> res;
        for(int i=0; i<=last-10;  i++){
            string sub_str = s.substr(i,10);
            if(_set.count(sub_str)==1){
                if(res_set.count(sub_str)==0){
                    res.push_back(sub_str);
                    res_set.insert(sub_str);
                }
                else{
                }
            }
            else if(_set.count(sub_str) == 0){
                _set.insert(sub_str);
            }
            else{

            }
        }
        return res;
    }
};