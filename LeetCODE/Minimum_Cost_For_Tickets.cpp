class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366,1e6);
        dp[0] = 0;
        for(int i = 1; i <= days[days.size()-1]; ++i){
            auto x = lower_bound(days.begin(),days.end(),i);
            if(x==days.end() || *x!=i){
                dp[i] = dp[i-1];
                continue;
            }
            dp[i] = min(dp[i],dp[i-1] + costs[0]);
            if(i>7)
                dp[i] = min(dp[i],dp[i-7] + costs[1]);
            else
                dp[i] = min(dp[i],costs[1]);
            if(i>30)
                dp[i] = min(dp[i],dp[i-30] + costs[2]);
            else
                dp[i] = min(dp[i],costs[2]);
            //cout<<dp[i]<<' ';
        }
        return dp[days[days.size()-1]];
    }
};