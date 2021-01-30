class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1,0);
        if(num==0)
            return dp;
        dp[1] = 1;
        int temp = 2;
        for(int i = 2; i <= num; ++i){
            if(i==temp){
                dp[i] = 1;
                temp*=2;
            }
            else{
                dp[i] = dp[i-temp/2]+1;
            }
        }
        return dp;
    }
};