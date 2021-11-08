#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int* arr = new int[n+1];      //used for DP
        arr[0] = 1;                 //initial condition
        arr[1] = 1;
        for(int i=2; i<n+1; i++){
            arr[i] = 0;
        }

        for(int i=2; i<=n;  i++){
            for(int j=1; j<=i; j++){
                arr[i] += arr[j-1] * arr[i-j];
            }
        }
        int ans = arr[n];
        delete []arr;

        return ans;
    }
};

int main(){
    Solution sol;
    cout<<sol.numTrees(3)<<endl;
    
}