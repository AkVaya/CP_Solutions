class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &curr,vector<int> &nums){
        if(curr.size()>=nums.size()){
            ans.push_back(curr);
            return ;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i]!=INT_MAX){
                int temp = nums[i];
                nums[i] = INT_MAX;
                curr.push_back(temp);
                backtrack(ans,curr,nums);
                curr.pop_back();
                nums[i] = temp;
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(res,temp,nums);
        return res;
    }
};