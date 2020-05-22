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
const ll M =1e9+7;
const ll nax=1e7+1;
void solve(){
    ll n;
    cin>>n;    
    ll dp[2][n+1];
    dp[0][1]=1;
    dp[1][1]=0;
    dp[1][0]=1;
    dp[0][0]=0;
    for (int i = 2; i <=n; ++i)
    {
        dp[1][i]=(3LL*dp[0][i-1])%M;
        dp[0][i]=(2LL*dp[0][i-1]%M + dp[1][i-1]%M)%M;
    }
    cout<<dp[1][n];
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