class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());    
        vector<vector<int> >res;
        if(nums.size()<=3)
            return res;
        for (int i = 0; i < nums.size()-3; ++i){
            if (i>0 && nums[i]==nums[i-1]) 
                    continue;
            for (int j = i+1; j < nums.size()-2; ++j){
                if (j>i+1 && nums[j]==nums[j-1]) 
                    continue;
                int l = j+1 ,r = nums.size()-1;
                while (l<r){
                    int sum = nums[i] + nums[l] + nums[r] + nums[j];
                    if (sum < target) l++;
                    if (sum > target) r--;
                    if (sum == target){
                        res.push_back(vector<int> {nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                        while (l < r && nums[l] == nums[l-1]) l++;
                        while (l < r && nums[r] == nums[r+1]) r--;  
                    }
                }
            }
        }
        return res;
    }
};