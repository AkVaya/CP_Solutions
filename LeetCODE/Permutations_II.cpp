class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &curr,vector<int> &nums,vector<bool> &vis){
        if(curr.size()>=nums.size()){
            ans.push_back(curr);
            return ;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(vis[i] || (i && !vis[i-1] && nums[i]==nums[i-1]))
                continue;
            curr.push_back(nums[i]);
            vis[i]=true;
            backtrack(ans,curr,nums,vis);
            vis[i]=false;
            curr.pop_back();
            
        }   
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int> curr;
        vector<bool>vis(nums.size(),false);
        backtrack(res,curr,nums,vis);
        return res;
    }
};