class Solution {
public:
    int cnt = 0;
    void backtrack(vector<vector<int>> &ans, vector<int> &curr,vector<int> &nums,int ind){
        ans.push_back(curr);
        if(ind==nums.size())
            return;
        for(int i = ind; i < nums.size(); ++i){
            curr.push_back(nums[i]);
            backtrack(ans,curr,nums,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(res,temp,nums,0);
        return res;
    }
};