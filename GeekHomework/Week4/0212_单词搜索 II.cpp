
//212. 单词搜索 II
//Trie Tree + DFS + Backtrack
class TrieNode{
    public:
    string word = "";
    vector<TrieNode*> nodes;
    TrieNode():nodes(26, 0){}
};
class Solution {
public:
    int rows,cols;
    vector<string> res;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = rows ? board[0].size() : 0;
        
        //构造字典树存储单词
        TrieNode* root = new TrieNode;
        for(string word : words){
            TrieNode* cur = root;
            for(int i = 0; i < word.size(); ++i){
                int c = word[i] - 'a';
                if(cur->nodes[c] == 0){
                    cur->nodes[c] = new TrieNode;
                }
                cur = cur->nodes[c];
            }
            //构建完一个单词的搜索链，存储这个单词
            cur->word = word;
        }

        //字符网格中深度搜索单词
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                dfs(board, root, i, j);
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& board, TrieNode* root, int i, int j){
        //save state
        char c = board[i][j];

        //已搜索过 或 与字典无匹配
        if(c == '.' || root->nodes[c - 'a'] == 0) return;

        root = root->nodes[c - 'a'];//字典中匹配这个字符的节点
        //叶子节点，在字典中匹配到完整单词;后续还可能存在更长的单词，还不能返回！
        if(root->word != ""){
            res.push_back(root->word);
            root->word = "";
        }

        board[i][j] = '.';
        if(i > 0) dfs(board, root, i-1, j);
        if(j > 0) dfs(board, root, i, j-1);
        if(i < rows-1) dfs(board, root, i+1, j);
        if(j < cols-1) dfs(board, root, i, j+1);

        //reverse state
        board[i][j] = c;
    }
};

