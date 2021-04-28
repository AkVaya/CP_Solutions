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
    TreeNode* fun(vector<int>&a, int i,int mx){
        //cout<<i<<' ';
        if(i>=mx)
            return nullptr;
        TreeNode* res = new TreeNode(a[i]);
        int nxt = i+1;
        while(nxt<a.size() && a[nxt]<a[i])
            nxt++;
        //cout<<nxt<<endl;
        if(nxt!=i+1)
            res->left = fun(a, i+1, nxt);
        res->right = fun(a, nxt, mx);
        return res;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return fun(preorder, 0, preorder.size());
    }
};