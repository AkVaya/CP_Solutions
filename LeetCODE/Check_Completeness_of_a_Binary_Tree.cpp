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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);
        bool check = false;
        while(q.size()){
            
            TreeNode* curr = q.front();
            q.pop();
            if(curr->right && !curr->left){
                    return false;
            }
            else if(curr->right && curr->left){if(check)
                if(check)
                    return false;
                q.push(curr->left);
                q.push(curr->right);
            }
            else if(curr->left){
                if(check)
                    return false;
                check = true;
                q.push(curr->left);
            }
            else
                check = true;
        }
        return true;
    }
};