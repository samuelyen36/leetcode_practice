/*
https://leetcode.com/problems/valid-anagram/submissions/
242. Valid Anagram
*/
#include <string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr1[128]={0}, arr2[128]={0};
        for(char ch: s){
            arr1[ch]++;
        }
        for(char ch: t){
            arr2[ch]++;
        }
        for(int i=0; i<128;i++){
            if(arr1[i]!=arr2[i]){
                return false;
            }
        }
        return true;
    }
};