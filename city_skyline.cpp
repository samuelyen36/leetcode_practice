#include <vector>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int sum=0;
        vector<int> col(n, 0), row(n, 0);
        for(int i=0; i<n; i++){     //extract the max element of both column and row
            for(int j=0; j<n; j++){
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }
        int tmp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                tmp = min(row[i], col[j]);
                sum += tmp-grid[i][j];
            }
        }
        return sum;
    }
};