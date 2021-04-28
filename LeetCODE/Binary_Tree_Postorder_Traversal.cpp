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
        fun(res,root->left);
        fun(res,root->right);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        fun(res, root);
        return res;
        
    }
};
//Iterative
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {vector<int> res;
        if(!root)
            return res;
        TreeNode* curr = root;
        stack<TreeNode* > s1, s2;
        s1.push(root);
        while(s1.size()){
            curr = s1.top();
            s1.pop();
            s2.push(curr);
            if(curr->left){
                s1.push(curr->left);
            }
            if(curr->right){
                s1.push(curr->right);
            }
        }
        while(s2.size()){
            res.push_back(s2.top()->val);
            s2.pop();
        }
        return res;
    }
};