class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &curr,vector<int> &nums,int ind){
        ans.push_back(curr);
        if(ind==nums.size())
            return;
        for(int i = ind; i < nums.size(); ++i){
            if(i==ind || nums[i]!=nums[i-1] ){
                curr.push_back(nums[i]);
                backtrack(ans,curr,nums,i+1);
                curr.pop_back();    
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int> curr;
        backtrack(res,curr,nums,0);
        return res;
    }
};