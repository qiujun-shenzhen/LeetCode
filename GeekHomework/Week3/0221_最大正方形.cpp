
//221. 最大正方形

//解法 2维DP
//1.子问题  以m[i][j]为右下角的正方形的最大边长
//2.状态    m[i][j] '0','1'   (row==0 || col==0; row!=0 && col!=0)
//3.方程    m[i][j]=='0' --> dp[row][col]=0 (i==0 || j==0; i!=0 && j!=0)
//          m[i][j]=='1' --> dp[row][col]=1 (i==0 && j==0 || i==0 && j!=0)
//          m[i][j]=='1' --> if('1' == m[row-1][col] && '1' == m[row][col-1] && '1' == m[row-1][col-1])
//                           dp[row][col] = min(dp[row-1][col-1], min(dp[row-1][col], dp[row][col-1])) + 1

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(m, vector(n, 0));
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if('1' == matrix[row][col]){
                    if (0 == row || 0 == col) {
                        dp[row][col] = 1; 
                    } else {
                        //关键
                        dp[row][col] = min(dp[row-1][col-1], min(dp[row-1][col], dp[row][col-1])) + 1;
                    }
                }
                res = max(res, dp[row][col]);
            }
        }
        return res * res;
    }
};

