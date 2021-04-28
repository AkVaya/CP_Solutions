/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void fun(TreeNode* root, vector<int>& res, int lvl){
        if(!root)
            return;
        if(res.size()<lvl)
            res.push_back(root->val);
        fun(root->right, res,lvl + 1);
        fun(root->left, res,lvl + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        fun(root, res, 1);
        return res;
    }
};