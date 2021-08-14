/*
884. Uncommon Words from Two Sentences
https://leetcode.com/problems/uncommon-words-from-two-sentences/
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res;
        unordered_map <string, int> map;
        string word="";
        for(auto x: s1){        //traverse through element of s1
            if(x == ' ' || x == '\n' || x=='\0'){   //split, check map
                auto _find = map.find(word);
                if(_find == map.end()){     //not find
                    map[word] = 1;
                }
                else{
                    map[word]++;
                }
                word = "";
            }
            else{
                word += x;
            }
        }
        auto _find = map.find(word);
        if(_find == map.end()){     //not find
            map[word] = 1;
        }
        else{
            map[word]++;
        }
        word="";

        for(auto x: s2){
            if(x == ' ' || x == '\n' || x=='\0'){   //split and check map
                cout<< word<<endl;
                auto _find = map.find(word);
                if(_find == map.end()){     //not find
                    map[word] = 1;
                }
                else{
                    map[word]++;
                }
                word = "";
            }
            else{
                word += x;
            }
        }
        _find = map.find(word);
        if(_find == map.end()){     //not find
            map[word] = 1;
        }
        else{
            map[word]++;
        }



        for(auto it = map.begin(); it != map.end(); it++){
            if(it->second == 1){
                res.push_back(it->first);
            }
        }
        return res;
    }
};



int main(){

}