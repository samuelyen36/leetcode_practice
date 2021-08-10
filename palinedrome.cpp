class Solution {
public:
    bool isPalindrome(int x) {
        int _input = x;
        int remainder, reverse=0;

        if(x < 0)   return false;

        while(_input != 0){
            reverse = reverse*10;
            remainder = _input%10;
            reverse += remainder;
            _input /= 10;
        }
        if(reverse == x)    return true;
        else    return false;
    }
};


int main(){
    Solution sol;
    sol.isPalindrome(121);

    return 0;

}