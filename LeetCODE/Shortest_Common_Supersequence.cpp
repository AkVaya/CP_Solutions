class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.length(), m = t.length();
        int dp[n+1][m+1];
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= m; ++j){
                if(!i || !j)
                    dp[i][j] = 0;
                else if(s[i-1]==t[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        string lcs, res;
        //cout<<dp[n][m]<<endl;
        int i = n, j = m;
        while(i>0 && j>0){
            if(s[i-1]==t[j-1]){
                lcs+=s[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>=dp[i][j-1])
                i--;
            else
                j--;
        }
        if(!lcs.length())
            return s+t;
        reverse(lcs.begin(), lcs.end());
        //cout<<lcs<<endl;
        i = 0, j = 0;
        int k = 0;
        while(k<lcs.length()){
            if(s[i]==lcs[k] && t[j]==lcs[k]){
                res+=s[i];
                k++;
                i++;
                j++;
            }
            else if(s[i]==lcs[k]){
                res+=t[j++];
            }
            else if(t[j]==lcs[k]){
                res+=s[i++];
            }
            else{
                res+=s[i++];
                res+=t[j++];
            }
        }
        while(i<s.length())
            res+=s[i++];
        while(j<t.length())
            res+=t[j++];
        return res;
    }
};