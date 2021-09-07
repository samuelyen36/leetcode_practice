#include <string>
#include <iostream>
using namespace std;
/*
12. Integer to Roman
https://leetcode.com/problems/integer-to-roman/
*/
class Solution {
public:
    string intToRoman(int num) {                //greedy algorithm
        const string roman_arr[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        const int val_arr[] =      {1000, 900, 500, 400, 100, 90,   50,    40, 10,   9, 5, 4, 1};
        string ans;
        int curr_idx = 0;
        while(num!=0){
            if(num >= val_arr[curr_idx]){
                ans += roman_arr[curr_idx];
                num -= val_arr[curr_idx];
            }
            else{
                curr_idx++;
            }
        }  

        return ans;
    }
};

int main(){
    Solution sol;
    cout<<sol.intToRoman(1994)<<endl;
    return 0;
}