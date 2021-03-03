/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(vector<int>& res, TreeNode* root,int k, int curr){
        if(!root)
            return;
        if(curr==k){
            res.push_back(root->val);
        }
        else if(curr<k){
            dfs(res,root->left,k,curr+1);
            dfs(res,root->right,k,curr+1);   
        }
    }
    int find(vector<int>& res, TreeNode* root,int target,int k){
        if(!root)
            return -1;
        if(root->val==target){
            dfs(res,root,k,0);
            return 1;
            
        }
        int val = find(res,root->left,target,k);
        if(val!=-1){
            if(val==k){
                res.push_back(root->val);
                return -1;
            }
            else if(val<k){
                dfs(res,root->right,k,val+1);
                return val + 1;
            }
        }
        val = find(res,root->right,target,k);
        if(val!=-1){
            if(val==k){
                res.push_back(root->val);
                return -1;
            }
            else if(val<k){
                dfs(res,root->left,k,val+1);
                return val + 1;
            }
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        if(K==0){
            res.push_back(target->val);
            return res;
        }
        find(res,root,target->val,K);
        return res;
    }
};