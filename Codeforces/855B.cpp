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
const ll nax=2001;
void solve(){
    ll n,x[3],mx=-inf,mn=inf;
    cin>>n>>x[0]>>x[1]>>x[2];
    ll a[n];
    ll ans=0;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    ll dp[n][3];
    dp[0][0]=a[0]*x[0];
    dp[0][1]=a[0]*x[0]+a[0]*x[1];
    dp[0][2]=a[0]*x[0]+a[0]*x[1]+a[0]*x[2];
    //cout<<dp[0][0]<< " "<<dp[0][1]<<" "<<dp[0][2]<<endl;
    for (int i = 1; i < n; ++i)
    {
        dp[i][0]=max(dp[i-1][0],a[i]*x[0]);
        dp[i][1]=max(dp[i-1][1],dp[i][0]+a[i]*x[1]);
        dp[i][2]=max(dp[i-1][2],dp[i][1]+a[i]*x[2]);
      //  cout<<dp[i][0]<< " "<<dp[i][1]<<" "<<dp[i][2]<<endl;
    }
    cout<<dp[n-1][2]<<endl;
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