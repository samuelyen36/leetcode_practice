class Solution {
public:
    int tribonacci(int n) {
        int ans[38]={0,1,1};
        if(n < 3){
            return ans[n];
        }
        for(int i=3; i<38; i++){
            ans[i] = ans[i-1]+ans[i-2]+ans[i-3];
            if(i == n){
                return ans[i];
            }
        }
        return 0;
    }
};