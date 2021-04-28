class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int dp[s.length()+1][t.length()+1];
        for(int i = 0; i <= s.length(); ++i){
            for(int j = 0; j <= t.length(); ++j){
                if(!i || !j){
                    dp[i][j] = 0;
                    continue;
                }
                else{
                    if(s[i-1]==t[j-1])
                        dp[i][j] = 1 + dp[i-1][j-1];
                    else
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[s.length()][t.length()];
    }
};