#include <vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int depth = matrix.size(), width = matrix[0].size();
        int min_sum;
        for(int i=1; i<depth; i++){
            for(int j=0; j<width; j++){
                //matrix[i-1][max(0,j-1)]       row-1
                //matrix[i-1][j]
                //matrix[i-1][min(width-1, j+1)]
                matrix[i][j] =  matrix[i][j] + min(matrix[i-1][max(0,j-1)], min(matrix[i-1][j],matrix[i-1][min(width-1, j+1)]));
            }
        }
        min_sum = matrix[depth-1][0];
        for(int j=1; j<width; j++){
            min_sum = min(matrix[depth-1][j],min_sum);
        }
        
        return min_sum;
    }
};