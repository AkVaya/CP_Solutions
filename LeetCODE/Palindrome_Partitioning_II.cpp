class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if(!n || !(n-1))
            return 0;
        vector<int>res(n+1, n-1);
        vector<vector<int> >dp(n, vector<int>(n, 0));
        for(int r = 0; r < n; ++r){
            for(int l = r; l >= 0; --l){
                if(s[l]==s[r] && (r-l<=2 || dp[l+1][r-1])){
                    dp[l][r] = 1;
                }
            }
        }
        res[0] = -1;
        for(int r = 1; r <= n; ++r){
            for(int l = 1; l <= r; ++l){
                if(dp[l-1][r-1]){
                    res[r] = min(res[r], res[l-1] + 1);
                }
            }
        }
        return res[n];
    }
};