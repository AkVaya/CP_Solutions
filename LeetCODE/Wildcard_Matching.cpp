class Solution {
public:
    bool fun(int i, int j, string& s, string& p,vector<vector<int> > &dp) {
        //cout<<i<<' '<<j<<endl;
        if(j==p.size())
            return i==s.size();
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(p[j]=='*')
            return dp[i][j] = (fun(i, j+1, s, p, dp) || (i<s.length() && fun(i+1, j, s, p, dp)));
        if(i<s.length() && (p[j]=='?' || s[i]==p[j]))
            return dp[i][j] = fun(i+1, j+1, s, p, dp);
        return dp[i][j] = 0;
    }
    bool isMatch(string s, string p) {
        vector<vector<int> > dp(s.size()+1,vector<int>(p.size(),-1));
        return fun(0, 0, s, p, dp);
    }
};