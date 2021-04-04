
//22. 括号生成

//DFS+回溯
//string[0] = '('
//string[2n-1] = ')'
//r <= l <= n
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n <= 0) return res;

        string s = "";
        dfs(n, s, 0, 0, res);
        return res;
    }
    void dfs(const int n, string s, int l, int r, vector<string> &res){
        if(l == n && r == n){
            res.push_back(s);
            return;
        }
        //不同的分支，需要回溯状态!
        if(l < n){
            s.push_back('(');
            dfs(n, s, l+1, r, res);
            s.pop_back();
        }
        if(r < l){
            s.push_back(')');
            dfs(n, s, l, r+1, res);
            s.pop_back();
        }
    }
};

