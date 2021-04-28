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
//Recursive
class Solution {
public:
    void fun(vector<int>&res, TreeNode* root){
        if(!root)
            return;
        res.push_back(root->val);
        fun(res,root->left);
        fun(res,root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        fun(res, root);
        return res;
    }
};
//Iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        TreeNode* curr = root;
        stack<TreeNode* > s;
        s.push(root);
        while(s.size()){
            curr = s.top();
            s.pop();
            res.push_back(curr->val);
            if(curr->right){
                s.push(curr->right);
            }
            if(curr->left){
                s.push(curr->left);
            }
        }
        return res;
    }
};