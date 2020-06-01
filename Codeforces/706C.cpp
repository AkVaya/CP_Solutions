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
const ll nax=1e5+1;
void solve(){
    ll n;
    cin>>n;
    ll cost[n],dp[n][2];
    string s[n],temp[2];
    for (int i = 0; i < n; ++i)
        cin>>cost[i];
    for (int i = 0; i < n; ++i){
        cin>>s[i];
        dp[i][0]=dp[i][1]=M;
    }
    dp[0][0]=0;
    dp[0][1]=cost[0];
    for (int i = 1; i < n; ++i)
    {
        temp[0]=s[i];
        temp[1]=s[i-1];
        reverse(temp[0].begin(),temp[0].end());
        reverse(temp[1].begin(),temp[1].end());
        if(s[i]>=s[i-1])
            dp[i][0]=min(dp[i][0],dp[i-1][0]);
        if(temp[0]>=s[i-1])
            dp[i][1]=min(dp[i-1][0]+cost[i],dp[i][1]);
        if(temp[0]>=temp[1])
                dp[i][1]=min(dp[i][1],dp[i-1][1]+cost[i]);
        if(s[i]>=temp[1])
                dp[i][0]=min(dp[i][0],dp[i-1][1]);
       // cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }
    if(min(dp[n-1][0],dp[n-1][1])==M)
        cout<<-1<<endl;
    else
        cout<<min(dp[n-1][0],dp[n-1][1])<<endl;

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