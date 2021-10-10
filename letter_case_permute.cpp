#include <vector>
#include <iostream>
using namespace std;
/*
784. Letter Case Permutation
https://leetcode.com/problems/letter-case-permutation/
*/
class Solution {
private:
    void backtracking(vector<string>&, string&, vector<int>&, int);
public:
    vector<string> letterCasePermutation(string s) {
        vector<int> idx_letter;
        vector<string> res;
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if((c>='a' && c<='z') || (c>='A' && c<='Z')){
                idx_letter.push_back(i);
            }
        }
        this->backtracking(res, s, idx_letter, 0);
        return res;
    }
};

void Solution::backtracking(vector<string>& res, string& s, vector<int>& idx_letter, int idx){
    res.push_back(s);
    //cout<<"push: "<<s<<endl;
    if(idx == idx_letter.size()){
        return;
    }
    for(int i=idx; i<idx_letter.size(); i++){
        int tmp = idx_letter[i];
        if(s[tmp]>='a' && s[tmp]<='z'){
            s[tmp] = s[tmp] - ('a'-'A');        //transfer to large case
        }
        else if(s[tmp]>='A' && s[tmp]<='Z'){
            s[tmp] = s[tmp] + ('a'-'A');        //transfer to large case
        }

        backtracking(res, s, idx_letter, i+1);

        if(s[tmp]>='a' && s[tmp]<='z'){
            s[tmp] = s[tmp] - ('a'-'A');        //transfer to large case
        }
        else if(s[tmp]>='A' && s[tmp]<='Z'){
            s[tmp] = s[tmp] + ('a'-'A');        //transfer to large case
        }
    }
    return;
}


int main(){
    Solution sol;
    string str = "ABC";
    for(string tmp: sol.letterCasePermutation(str)){
        cout<<tmp<<endl;
    }
    return 0;
}