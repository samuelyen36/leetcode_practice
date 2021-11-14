#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/iterator-for-combination/
1286. Iterator for Combination
*/
class CombinationIterator {
private: 
    vector<string> vec;
    int idx;
    void generate_allcomb(vector<string>& vec, string characters, int length);
public:
    CombinationIterator(string characters, int combinationLength) {
        generate_allcomb(vec, characters, combinationLength);
        this->idx = 0;
    }
    
    string next() {
            idx++;
            return vec[idx-1];
    }
    
    bool hasNext() {
        if(idx < vec.size()){
            return true;
        }
        else{
            return false;
        }
    }
};

void CombinationIterator::generate_allcomb(vector<string>& vec, string characters, int length){
    int mask = 1<<characters.size();        //shift to rightmost bit
    reverse(characters.begin(), characters.end());
    for(int i=1; i<mask; i++){
        int val = mask-i;
        int it=0;
        string str("");
        while(val!=0){
            if(val&1 != 0){     //select this string
                str = str+characters[it];
            }
            it++;
            val = val>>1;
        }
        if(str.size() == length){
            reverse(str.begin(), str.end());
            vec.push_back(str);
        }
    }
    return;
}


/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */