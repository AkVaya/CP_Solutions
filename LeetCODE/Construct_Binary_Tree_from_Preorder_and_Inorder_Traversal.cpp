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
    TreeNode* fun(vector<int>& pre, vector<int>& in, int l, int r, int &ind, unordered_map<int, int>& m){
        if(l>r)
            return NULL;
        TreeNode* curr = new TreeNode(pre[ind++]);
        int i = m[curr->val];
        if(i>r || i <l)
            return curr;
        curr->left = fun(pre, in, l, i-1, ind, m);
        curr->right = fun(pre, in, i+1, r, ind, m);
        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < inorder.size(); ++i)
            m[inorder[i]] = i;
        return fun(preorder, inorder, 0, preorder.size()-1, ind, m);
    }
};