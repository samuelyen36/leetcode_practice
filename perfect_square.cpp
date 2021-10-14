#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<unsigned int> vec(n+1, __INT_MAX__);
        vec[0] = 0;
        for(int i=0; i<=n; i++){
            for(int j=1; j*j<=i; j++){
                vec[i] = min(vec[i], vec[i-j*j]+1);
            }
        }
        return vec[n];
    }
};

int main(){
    Solution sol;
    cout<<sol.numSquares(13)<<endl;
}