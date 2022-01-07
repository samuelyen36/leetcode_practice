#include <string>
#include <vector>
#include <memory.h>
using namespace std;

class Solution {
private:
    bool* res_vec;
    bool check_len0(string, vector<string>&);
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size()==1){
            return this->check_len0(s, wordDict);
        }
        res_vec = new bool[s.size()];
        memset(res_vec, 0, sizeof(bool)*s.size());
        string _init = s.substr(0,1);
        for(auto tmp: wordDict){
            if(tmp==_init){
                res_vec[0] = true;
                break;
            }
        }
        
        for(int i=0; i<s.size(); i++){
            for(int j=i-1; j>=0; j--){
                if(res_vec[j]==true){
                    string substring = s.substr(j+1, i-j);
                    for(string tmp: wordDict){
                         if(substring == tmp){
                            res_vec[i] = true;
                            break;
                        }
                    }
                }
                if(j==0){
                    string substring = s.substr(j, i-j+1);
                    for(string tmp: wordDict){
                        if(substring == tmp){
                            res_vec[i] = true;
                            break;
                        }
                    }
                }
            }
        }
        bool res = res_vec[s.size()-1];
        delete []res_vec;
        return res;
    }
};

bool Solution::check_len0(string s, vector<string>& vec){
    for(auto tmp: vec){
        if(s == tmp){
            return true;
        }
    }
    return false;
}
