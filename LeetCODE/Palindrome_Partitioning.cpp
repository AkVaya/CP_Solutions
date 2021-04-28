class Solution {
public:
    void fun(vector<vector<string> >&res, vector<string>& curr, int l, string &s, vector<vector<bool>>&dp){
        if(l>=s.length()){
            res.push_back(curr);
            return;
        }
        for(int i = l; i < s.length(); ++i){
            if(s[l]==s[i] && (i-l+1<=3 || dp[l+1][i-1])){
                dp[l][i] = true;
                curr.push_back(s.substr(l, i-l+1));
                fun(res, curr, i+1, s, dp);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> temp;
        vector<vector<bool>>dp(s.length(), vector<bool>(s.length(), false));
        fun(res, temp, 0, s, dp);
        return res;
    }
};