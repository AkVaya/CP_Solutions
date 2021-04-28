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
//recursive
class Solution {
public:
    void fun(vector<int>&res, TreeNode* root){
        if(!root)
            return;
        fun(res,root->left);
        res.push_back(root->val);
        fun(res,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        fun(res, root);
        return res;
    }
    
};
//iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        stack<TreeNode* > s;
        s.push(curr);
        while(s.size() || curr){
            while(curr && curr->left){
                s.push(curr->left);
                curr = curr->left;
            }
            TreeNode * temp = s.top();
            s.pop();
            if(!temp)
                continue;
            res.push_back(temp->val);
            curr = temp->right;
            s.push(curr);
            
        }
        return res;
    }
    
};