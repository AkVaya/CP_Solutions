class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long res = -2147483647,mx = 0;
        for(auto i : nums){
            mx+=i;
            if(mx>res)
                res = mx;
            if(mx<0)
                mx = 0;
        }
        return res;
    }
};