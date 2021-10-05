using namespace std;
#include <stdlib.h> 
#include <iostream>
/*
70. Climbing Stairs
https://leetcode.com/problems/climbing-stairs/
*/
class Solution {
private:
    int *arr;
public:
    Solution(void);
    int climbStairs(int n) {
        /*int* arr = new int[n+1];
        arr[0] = 1;
        arr[1] = 1;
        for(int i=2; i<=n; i++){
            arr[i] = arr[i-1] + arr[i-2];
        }*/
        return this->arr[n];
    }
};

Solution::Solution(void){
    this->arr = new int[45];
    this->arr[0] = 1;
    this->arr[1] = 1;
    for(int i=2; i<=45; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
}

int main(int argc, char** argv){
    Solution sol;
    cout<<sol.climbStairs(atoi(argv[1]))<<endl;
    return 0;
}