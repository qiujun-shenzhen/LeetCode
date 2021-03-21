
//51. N 皇后

//解法一：递归（回溯）
class Solution{
public:
    vector<vector<string>> solveNQueens(int n){
        vector<vector<string>> solutions;
        //每行的放置记录
        vector<int> queens(n,-1);
        //列，左右对角线
        unordered_set<int> columns;
        unordered_set<int> diagonal1;
        unordered_set<int> diagonal2;
        backtrack(solutions, queens, n, 0, columns, diagonal1, diagonal2);
        return solutions;
    }
    void backtrack(vector<vector<string>> &solutions, vector<int> &queens, const int n, int row,
        unordered_set<int> &columns, unordered_set<int> &diagonals1, unordered_set<int> &diagonals2){
        if (row == n) {
            //terminal
            vector<string> board = generateBoard(queens,n);
            solutions.push_back(board);
        } else {
            //第row行，寻找合适位置
            for (int i = 0; i < n; ++i) {
                //process
                if (columns.find(i) != columns.end()) continue;
                int diagonal1 = row - i;
                if (diagonals1.find(diagonal1) != diagonals1.end()) continue;
                int diagonal2 = row + i;
                if (diagonals2.find(diagonal2) != diagonals2.end()) continue;

                queens[row] = i;
                columns.insert(i);
                diagonals1.insert(diagonal1);
                diagonals2.insert(diagonal2);

                //down
                backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);

                //reverse current level's modify;rather than all!!!
                queens[row] = -1;
                columns.erase(i);//columns.clear();
                diagonals1.erase(diagonal1);//diagonals1.clear();
                diagonals2.erase(diagonal2);//diagonals2.clear();
            }
        }
    }
    vector<string> generateBoard(vector<int> queens, const int n){
        vector<string> board;
        for (int i = 0; i < n; ++i) {
            //直接构造后再填充
            string row(n,'.');    
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
}

/////////////////////////////////////////////////////////////////////////////




