
//200. 岛屿数量

//解法一：递归（DFS）
class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c, int rows, int cols){
		//已被开发过
        grid[r][c] = 0;
        //左右上下4个方向搜索
        if(r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r-1, c, rows, cols);
        if(r + 1 < rows && grid[r+1][c] == '1') dfs(grid, r+1, c, rows, cols);
        if(c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c-1, rows, cols);
        if(c + 1 < cols && grid[r][c+1] == '1') dfs(grid, r, c+1, rows, cols);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int nums=0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int r = 0; r < rows; ++r){
            for(int c = 0; c < cols; ++c){
                if(grid[r][c] == '1'){
					//发现新大陆
                    ++nums;
                    dfs(grid, r, c, rows, cols);
                }
            }      
        }
        return nums;
    }
};
