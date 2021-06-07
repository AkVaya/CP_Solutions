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
    int fun(TreeNode* root, int &mx, unordered_map<int, int> &freq){
        if(!root)
            return 0;
        int sum = root->val + fun(root->left, mx, freq) + fun(root->right, mx, freq); 
        freq[sum]++;
        mx = max(mx, freq[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> freq;
        int mx = 0;
        fun(root, mx, freq);
        vector<int> res;
        for(auto i : freq)
            if(i.second==mx)
            res.push_back(i.first);
        return res;
    }
};