#include <vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int depth = matrix.size(), width = matrix[0].size();
        int min_sum = 0;
        for(int i=0; i<width; i++){
            for(int j=1; j<depth; j++){
                //matrix[max(width-1, i+1)][j]      row+1, col
                //matrix[]
                matrix[i][j] =  min(matrix[])
            }
        }
    }
};