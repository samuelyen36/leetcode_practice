#include <string>
using namespace std;
/*
1328. Break a Palindrome
https://leetcode.com/problems/break-a-palindrome/
*/
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len = palindrome.size();
        if(len == 1){
            return "\0";
        }
        for(int i=0; i<len/2; i++){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[len-1] = 'b';
        return palindrome;
    }
};