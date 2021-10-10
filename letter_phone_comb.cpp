#include <vector>
#include <string>
#include <iostream>
/*
17. Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/
using namespace std;

class Solution {
private:
    vector<string> phone_char = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; //stands for 2~9
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        for(int i=0; i<digits.size(); i++){     //iterate through the input digits
            vector<string> this_step;
            int tmp = res.size();
            if(tmp==0){
                //cout<<(digits[i] - '0') -2 <<endl;
                string this_dig = phone_char[(digits[i] - '0') -2 ];
                for(int k=0; k<this_dig.size(); k++){
                        string tmp_str(1, this_dig[k]);
                        res.push_back(tmp_str);
                }
            }
            else{       
                for(int j=0; j<tmp; j++){
                   // cout<<(digits[i] - '0') -2 <<endl;
                    string this_dig = phone_char[(digits[i] - '0') -2 ];
                    for(int k=0; k<this_dig.size(); k++){
                            string tmp_str = res[j] + this_dig[k];
                            this_step.push_back(tmp_str);
                    }
                }
                res = this_step;
            }
        }
        return res;
    }
};


int main(){
    Solution sol;
    for(string s: sol.letterCombinations("234")){
        cout<<s<<endl;
    }
}