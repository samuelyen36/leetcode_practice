#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0){
            return 1;
        }
        vector<vector<int>> vec(amount+1, vector<int> (amount+1, 0));
        int res = 0;
        for(int t: coins){
            if(t <= amount){
                vec[1][t] = 1;
            }
        }
        for(int i=2; i<=amount; i++){
            for(int j=1; j<=amount; j++){
                for(int candidate: coins){
                    int tmp = j-candidate;
                    if(tmp>0){
                        vec[i][j] += vec[i-1][tmp];
                    }
                }
                printf("%d ", vec[i][j]);
            }
            printf("\n");
        }
        for(int i=1; i<=amount; i++){
            res = max(res,vec[i][amount]);
        }
        return res;
    }
};