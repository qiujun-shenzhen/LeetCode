
//144. 二叉树的前序遍历

//解法一：递归
//递归优化：注意引用传值！！！
//1.调用自身不需要check null;因为函数开头已经做了
//2.check null使用比较而不是取反
//3.使用辅助函数可以减少内存消耗
class Solution {
public:
    void preorder(TreeNode* root,vector<int> &res){
        if(root == nullptr) return;
        res.push_back(root->val);
        preorder(root->left,res);
        preorder(root->right,res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root,res);
        return res;   
    }
};

//////////////////////////////////////////////////////