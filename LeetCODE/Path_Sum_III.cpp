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
    void fun(TreeNode* root, int sum, vector<int> &temp, int &res){
        if(!root)
            return;
        temp.push_back(root->val);
        fun(root->left, sum, temp, res);
        fun(root->right, sum, temp, res);
        int curr = 0;
        for(int i = temp.size()-1; i >= 0; --i){
            curr+=temp[i];
            if(curr==sum)
                res++;
        }
        temp.pop_back();
    }
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        vector<int> temp;
        fun(root, sum, temp, res);
        return res;
    }
};