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
using namespace std;
const ll M =998244353;
const ll nax=2001;
void add(ll &a,ll b){
    a+=b;
    a%=M;
}
void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll dp[n+1][k+1];
    memset(dp,0,sizeof(dp));
    dp[1][0]=m;
    for (int i = 1; i <=n; ++i)
    {
        for (int j = 0; j <=k; ++j)
        {
            if(dp[i][j])
                continue;
            if(i)
                add(dp[i][j],dp[i-1][j]);
            if(j)
                add(dp[i][j],(m-1)*dp[i-1][j-1]);
        }
    }
   // for (int i = 0; i <= n; ++i)
   // {
   //     for (int j = 0; j <= k; ++j)
   //     {
   //         cout<<dp[i][j]<<" ";
   //     }
   //     cout<<endl;
   // }
    cout<<dp[n][k]<<endl;
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
   // cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
   // cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}