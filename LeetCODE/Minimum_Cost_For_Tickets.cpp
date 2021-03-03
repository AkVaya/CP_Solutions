class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366,INT_MAX);
        dp[0] = 0;
        for(int i = 1; i < 366; ++i){
            auto it = lower_bound(days.begin(),days.end(),i);
            if(it==days.end() || *it!=i){
                dp[i] = dp[i-1];
            //    cout<<i<<' '<<dp[i]<<endl;
                continue;
            }
            if(i>=1 && dp[i-1]!=INT_MAX)
                dp[i] = min(dp[i],costs[0] + dp[i-1]);
            if(i>=7 && dp[i-7]!=INT_MAX)
                dp[i] = min(costs[1] + dp[i-7],dp[i]);
            else dp[i] = min(dp[i],costs[1]);
            if(i>=30 && dp[i-30]!=INT_MAX)
                dp[i] = min(dp[i],costs[2] + dp[i-30]);
            else dp[i] = min(dp[i],costs[2]);
            //cout<<i<<' '<<dp[i]<<endl;
        }
        return dp[days[days.size()-1]];
    }
};