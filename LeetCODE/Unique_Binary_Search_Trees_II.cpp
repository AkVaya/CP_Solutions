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
    vector<TreeNode*> fun(int start,int end){
        vector<TreeNode*> res;
        if(start>end){
            res.push_back(NULL);
            return res;
        }
        for(int i = start; i <= end; ++i){
            vector<TreeNode*> l = fun(start,i-1);
            vector<TreeNode*> r = fun(i+1,end);
            for(auto x : l){
                for(auto y : r){
                    TreeNode* curr = new TreeNode(i);
                    curr->left = x;
                    curr->right = y;
                    res.push_back(curr);
                }
            }
                                         
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return fun(1,n);
    }
};