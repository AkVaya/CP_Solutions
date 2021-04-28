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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(!root)
            return res;
        int flip = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            vector<int> temp;
            int sz = q.size();
            while(sz>0){
                TreeNode* curr = q.front();
                temp.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                q.pop();
                sz--;
            }
            if(flip)
                reverse(temp.begin(),temp.end());
            res.push_back(temp);
            flip = 1 - flip;
        }
        return res;
    }
};