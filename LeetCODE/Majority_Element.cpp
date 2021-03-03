class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, res = 0;
        for(auto i : nums){
            if(!cnt){
                cnt++;
                res = i;
            }
            else if(i==res)
                cnt++;
            else cnt--;
        }
        return res;
    }
};