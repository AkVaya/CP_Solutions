class Solution {
public:
    vector<vector<int> > ans;
    vector<int> nums;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        for(int i=0;i<candidates.size();i++){
            nums.push_back(candidates[i]);
        }
        vector<int> x;
        fun(0,x,0,target);
        return ans;
    }
    void fun(int index , vector<int> v , int start, int target){
        if(target==0){
            ans.push_back(v);
            return;
        }
        else if(target<0){
            return ;
        }
        else{
            for(int i=start;i<nums.size();i++){
                v.push_back(nums[i]);    
                fun(index+1,v,i,target-nums[i] );
                v.pop_back();
            }
        }
    }
};