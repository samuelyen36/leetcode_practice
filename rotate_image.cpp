#include <vector>
#include <algorithm>
/*
48. Rotate Image
https://leetcode.com/problems/rotate-image/
*/
class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        std::reverse(matrix.begin(), matrix.end());

        for(int i=0; i<matrix.size(); i++){
            for(int j=i+1; j<matrix[0].size(); j++){
                if(i != j){
                    std::swap(matrix[i][j], matrix[j][i]);;
                }
            }
        }
    }
};