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
    TreeNode* fun(vector<int>& post, vector<int>& in, int l, int r, int &ind, unordered_map<int, int>& m){
        if(l>r)
            return NULL;
        TreeNode* curr = new TreeNode(post[ind--]);
        int i = m[curr->val];
        if(i>r || i <l)
            return curr;
        curr->right = fun(post, in, i+1, r, ind, m);
        curr->left = fun(post, in, l, i-1, ind, m);
        return curr;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ind = postorder.size()-1;
        unordered_map<int, int> m;
        for(int i = 0; i < inorder.size(); ++i)
            m[inorder[i]] = i;
        return fun(postorder, inorder, 0, inorder.size()-1, ind, m);
    }
};