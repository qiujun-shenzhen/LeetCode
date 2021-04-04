
//200. 岛屿数量
//DFS
class Solution {
public:
    int rows, cols;
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = rows ? grid[0].size() : 0;
        if(0 == rows || 0 == cols) return 0;

        int res = 0;
        for(int r = 0; r < rows; ++r){
            for(int c = 0; c < cols; ++c){
                if(grid[r][c] == '1'){
                    ++res;
                    dfs(grid, r, c);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>> &grid, int r, int c){
        if(grid[r][c] == '0') return;
        grid[r][c] = '0';
        if(r > 0) dfs(grid, r-1, c);
        if(c > 0) dfs(grid, r, c-1);
        if(r < rows-1) dfs(grid, r+1, c);
        if(c < cols-1) dfs(grid, r, c+1);
    }
};

