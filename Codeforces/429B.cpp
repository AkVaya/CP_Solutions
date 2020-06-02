#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<map>
#include<math.h>
#include<string.h>
#include<ctime>
#include<cmath>
#define ll long long
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
#define fr(i,a,b) for (int i = a; i < b; ++i)
using namespace std;
const ll M =1e18;
const ll nax=1e3+1;
ll a[nax][nax],dp[4][nax][nax];
void solve(){
    ll n,m,ans=0;
    cin>>n>>m;
    // dp1 : 1 1 to i j 
    // dp2 : i j to n m
    // dp3 : 1 m to i j
    // dp4 : i j to n 1
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m ; ++j)
            cin>>a[i][j]; 
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) 
            dp[0][i][j] = a[i][j] + max(dp[0][i][j-1],dp[0][i-1][j]);
    for(int i = n; i > 0; i--) 
        for(int j = m; j > 0; j--) 
            dp[1][i][j] = a[i][j] + max(dp[1][i][j+1],dp[1][i+1][j]);
    for(int i = 1; i <= n; i++) 
        for(int j = m; j > 0; j--) 
            dp[2][i][j] = a[i][j] + max(dp[2][i-1][j],dp[2][i][j+1]);
    for(int i = n; i > 0; i--) 
        for(int j = 1; j <= m; j++) 
            dp[3][i][j] = a[i][j] + max(dp[3][i+1][j],dp[3][i][j-1]);  
    for(int i = 2; i < n; i++) { 
        for(int j = 2; j < m; j++) {
            ll temp1 = dp[0][i-1][j] + dp[1][i+1][j] + dp[2][i][j+1] + dp[3][i][j-1];
            ll temp2 = dp[2][i-1][j] + dp[3][i+1][j] + dp[0][i][j-1] + dp[1][i][j+1];
            ans = max3(ans,temp1,temp2);
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    //cin>>t;
    //clock_t t3 = clock();
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}