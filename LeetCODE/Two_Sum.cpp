class Solution {
public:
    #define pb push_back
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            int diff = target-nums[i];
            auto it = m.find(diff);
            if(it!=m.end()){
                res.pb(i);
                res.pb(it->second);
                return res;
            }
            m[nums[i]]=i;
        }
        return res;
    }
};