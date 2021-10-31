#include <iostream>

class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist=0;
        int _xor = x^y;
        while(_xor != 0){
            dist = dist+(_xor&1);
            _xor = _xor>>1;
        }
        return dist;
    }
};

int main(){
    Solution sol;
    std::cout<<sol.hammingDistance(1,3)<<std::endl;
    return 0;
}