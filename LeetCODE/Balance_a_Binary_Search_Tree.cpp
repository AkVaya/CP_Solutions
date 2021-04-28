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
    void get(TreeNode* root, vector<TreeNode *>& a){
        if(!root)
            return;
        get(root->left, a);
        a.push_back(root);
        get(root->right, a);
    }
    TreeNode* build(vector<TreeNode *> &a, int l,int r){
        if(l>r)
            return nullptr;
        int mid https://assets.leetcode.com/uploads/2019/08/22/1515_ex1_out.png= (l + r)/2;
        TreeNode * root = a[mid];
        root->left = build(a, l, mid-1);
        root->right = build(a, mid + 1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode *> a;
        get(root, a);
        return build(a, 0, a.size()-1);
    }
};