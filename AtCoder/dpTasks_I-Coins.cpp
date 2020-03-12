#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    double prob[n+1],dp[n+1][n+1]={0}, res = 0;
    for(int i = 1; i <= n; ++i)
        cin>>prob[i];
    dp[0][0]=1;
    for (int i = 1; i <=n; ++i)
    {
        for (int j = 0; j<=i; ++j)
        {
            if(j)   dp[i][j]+=(dp[i-1][j-1]*prob[i]);
            dp[i][j]+=((1.0-prob[i])*dp[i-1][j]);
        }
    }
    for (int i = (n/2+1); i <= n; ++i)
    {
        res+=dp[n][i];
    }
    printf("%.10lf",res);
    
    return 0;
}
