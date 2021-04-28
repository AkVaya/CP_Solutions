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
    int ht(TreeNode* root){
        if(!root)
            return 0;
        return 1 + max(ht(root->left), ht(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        int left = ht(root->left);
        int right = ht(root->right);
        return (abs(left-right)<=1 && isBalanced(root->left) && isBalanced(root->right));
    }
};