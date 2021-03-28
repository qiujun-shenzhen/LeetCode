
//64. 最小路径和

//1.子问题 
//2.状态
//3.dp方程 minSum[i][j] = min(minSum[i-1][j],minSum[i][j-1])

//解法二 1维DP
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> minSum(n, 0);
        for(int row = 0; row < m; ++row){
            for(int col = 0; col < n; ++col){
                if(0 == row && 0 == col){
                    minSum[col] = grid[row][col];
                } else if (0 == row) {
                    minSum[col] = grid[row][col] + minSum[col-1];
                } else if(0 == col) {
                    minSum[col] =  grid[row][col] + minSum[col];
                } else {
                    minSum[col] = grid[row][col] + min(minSum[col-1], minSum[col]);
                }
            }
        }
        return minSum[n-1];
    }
};

//解法二 2维DP
/*
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> minSum(m, vector(n, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(0 == i && 0 == j){
                    minSum[i][j] = grid[i][j];
                } else if (0 == i) {
                    minSum[i][j] = grid[i][j] + minSum[i][j-1];
                } else if(0 == j) {
                    minSum[i][j] =  grid[i][j] + minSum[i-1][j];
                } else {
                    minSum[i][j] = grid[i][j] + min(minSum[i][j-1], minSum[i-1][j]);
                }
            }
        }
        return minSum[m-1][n-1];
    }
};
*/

///////////////////////////////////////////////////////////////////////////////
//解法一 DFS leetcode会超时
/*
class Solution {
public:
    int minsum = 0;
    void dfs(vector<vector<int>> &grid, int row, int col, int sum){
        if(row == grid.size() - 1 && col == grid[0].size() - 1){
            sum += grid[row][col];
            if(0 == minsum){
                minsum = sum;
            }else{
                minsum = min(minsum, sum);
            }
            return;
        }
        if(row < grid.size() - 1){
            dfs(grid, row + 1, col, sum + grid[row][col]);
        }
        if(col < grid[0].size() - 1){
            dfs(grid, row, col+1, sum + grid[row][col]);
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        dfs(grid, 0, 0, 0);
        return minsum;
    }
};
*/
