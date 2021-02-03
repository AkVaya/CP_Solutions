class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()+1];
        for(int i = 0; i < nums.size()+1; ++i){
            dp[i] = 100000;
        }
        for(int i = 0; i < nums.size(); ++i){
            auto it = lower_bound(dp+1,dp+nums.size()+1,nums[i]);
            *it = min(nums[i],*it);
        }
        for(int i = nums.size(); i>0; --i){
            if(dp[i]!=100000)
                return i;
        }
        return 1;
    }
};