#include <vector>
using  namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vec(m, vector<int> (n, 0));     //vec[m][n]
        vec[0][0] = grid[0][0];
        for(int i=1; i<n; i++){
            vec[0][i] = grid[0][i] + vec[0][i-1];
        }
        for(int i=1; i<m; i++){
            vec[i][0] = grid[i][0] + vec[i-1][0];
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                vec[i][j] = min(vec[i-1][j], vec[i][j-1]) + grid[i][j];
            }
        }
        return vec[m-1][n-1];

    }
};