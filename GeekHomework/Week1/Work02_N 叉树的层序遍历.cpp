
//429. N 叉树的层序遍历

//解法一：递归;DFS？
class Solution {
public:
    void levelHelper(Node* root,vector<vector<int>> &res,int level){
        if(root==nullptr) return;
        //当前层还没有开辟缓存则开辟；保存当前节点值
        if(res.size()<=level){
            res.push_back(vector<int>(1,root->val));
        }else{
            res[level].push_back(root->val);
        }
        //遍历子节点
        for(int i=0;i<root->children.size();++i){
            levelHelper(root->children[i],res,level+1);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        levelHelper(root,res,0);
        return res;
    }
};

///////////////////////////////////////////////////////////////////////


