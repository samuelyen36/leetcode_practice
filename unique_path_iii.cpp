#include <vector>
#include <iostream>
using namespace std;
/*
https://leetcode.com/problems/unique-paths-iii/
980. Unique Paths III
*/
class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j, int step_count, int target_step);

public:
    int uniquePathsIII(vector<vector<int>>& g) { //1=>start    2=>end     0=>available step    -1=>obstacle
  auto i1 = 0, j1 = 0, t_steps = 0;
  for (auto i = 0; i < g.size(); ++i)
    for (auto j = 0; j < g[0].size(); ++j) {
      if (g[i][j] == 1) i1 = i, j1 = j;
      if (g[i][j] != -1) ++t_steps;
    }
        auto res = dfs(g, i1, j1, 1, t_steps);
        cout<<res;
        return res;
    }
};

int Solution::dfs(vector<vector<int>>& grid, int i, int j,int step_count, int target_step){
    //cout<<i<<'\t'<<j<<endl;
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || step_count>target_step){
        return 0;
    }
    if(grid[i][j]==-1){
        return 0;
    }
    if(grid[i][j] == 2){            //reach the target
        if(step_count == target_step){  //meet the required step
            return 1;
        }
        else{
            return 0;
        }
    }

    grid[i][j] = -1;
    int res;
    res = dfs(grid, i-1, j, step_count+1, target_step) + dfs(grid, i+1, j, step_count+1, target_step) \
          + dfs(grid, i, j-1, step_count+1, target_step)+ dfs(grid, i, j+1, step_count+1, target_step);
    grid[i][j] = 0;
    return res;
}


int main(){
    vector<vector<int>> grid{{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    Solution sol;
    cout<<sol.uniquePathsIII(grid);
    return 0;
}