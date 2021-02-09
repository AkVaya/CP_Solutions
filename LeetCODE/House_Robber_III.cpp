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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> m;
        return fun(root,m);
    }
    int fun(TreeNode* root,unordered_map<TreeNode*,int>& m){
        if(!root)
            return 0;
        if(m.count(root))
            return m[root];
        int curr = root->val;
        int res = curr;
        int val = 0;         
        if(root->left)
            val += fun(root->left->left,m) + fun(root->left->right,m);
        if(root->right)
            val += fun(root->right->left,m) + fun(root->right->right,m) ;
        res += val;
        res = max(res,fun(root->left,m) + fun(root->right,m));
        return m[root] = res;
    }
};