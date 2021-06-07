class Solution {
public:
    int maxProfit(int k, vector<int>& a) {
        int n = a.size();
        if(!n)
            return 0;
        vector<vector<int> > dp(k+1, vector<int>(n, 0));
        for(int i = 1; i <= k; ++i){
            int mx = INT_MIN;
            for(int j = 0; j < n; ++j){
                if(j)
                    dp[i][j] = max(dp[i][j-1], mx + a[j]);
                mx = max(mx, dp[i-1][j] - a[j]);
            }
        }
        return dp[k][n-1];
    }
};