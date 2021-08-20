#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
using namespace std;
/*
301. Remove Invalid Parentheses
https://leetcode.com/problems/remove-invalid-parentheses/
https://leetcode.com/problems/remove-invalid-parentheses/discuss/75038/Evolve-from-intuitive-solution-to-optimal-a-review-of-all-solutions
*/
class Solution {
public:
    bool test_valid(string s){
        int left = 0;
        for(char c: s){
            if(c == '('){
                left++;
            }
            if(c == ')'){
                if(left == 0){
                    return false;
                }
                else{
                    left--;
                }
            }
        }
        if(left == 0){
            return true;
        }
        else{
            return false;
        }
    }
/*
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> seened;
        queue<string> to_test;      //queue: first in first  out
        to_test.push(s);

        while(!to_test.empty()){
            string tmp = to_test.front();   //get the first element of queue
            to_test.pop();
            if(test_valid(tmp)){        //this string(tmp) is valid expression
                if(seened.count(tmp) == 0){ //this combination is not seened before
                    seened.insert(tmp);
                    res.push_back(tmp);
                }
                continue;
            }
            else if(res.empty()){           //BFS, remove one more parenthe only if we can't find solution in this level
                for(int i=0; i<tmp.length(); i++){
                    if(tmp[i] == '(' || tmp[i] == ')'){
                        string sub_string = tmp.substr(0,i) + tmp.substr(i+1);
                        if(seened.count(sub_string)){
                            continue;
                        }
                        else{
                            to_test.push(tmp.substr(0,i) + tmp.substr(i+1));     //remove i-th position from string, which is a ( or ) parentheses
                        }
                    }
                }
            }
        }
        return res;
    }
*/
    vector<string> removeInvalidParentheses(string s) {
        queue<pair<string, int>> to_test;
        vector<string> res;
        to_test.push(make_pair(s,0));

        while(!to_test.empty()){
            auto tmp_pair = to_test.front();   //get the first element of queue
            string tmp = tmp_pair.first;
            int idx = tmp_pair.second;
            to_test.pop();
            if(test_valid(tmp)){
                res.push_back(tmp);
            }

            else if(res.empty()){           //BFS, remove one more parenthe only if we can't find solution in this level
                for(int i=idx; i<tmp.length(); i++){
                    if((tmp[i] == '(' || tmp[i] == ')') && (i==tmp_pair.second || tmp[i] != tmp[i-1])){
                        string sub_string = tmp.substr(0,i) + tmp.substr(i+1);
                        to_test.push(make_pair(sub_string, i));     //remove i-th position from string, which is a ( or ) parentheses
                    }
                }
            }
        }
        return res;
    }
};

int main(){

}