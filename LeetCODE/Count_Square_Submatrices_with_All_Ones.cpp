class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int> >dp(n,vector<int>(m,0));
        int res = 0;
        for(int i = 0 ; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(matrix[i][j]){
                    if(i && j)
                        dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                    dp[i][j] = max(1,dp[i][j]);
                    res+=dp[i][j];
                }
            }
        }
        return res;
    }
};