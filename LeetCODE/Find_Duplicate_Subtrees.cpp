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
    string fun(TreeNode* root, vector<TreeNode*> &res, unordered_map<string, int>& m){
        if(!root)
            return "";
        string l = fun(root->left, res, m), r = fun(root->right, res, m);
        string ret = "(" + l + to_string(root->val) + r + ")";
        if(m[ret]==1){
            res.push_back(root);
        }
        m[ret]++;
        return ret;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> m;
        fun(root, res, m);
        return res;
    }
};