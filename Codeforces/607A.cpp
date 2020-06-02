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
const ll nax=1e6+1;
ll dist[nax];
void solve(){
    ll n,mx=0;
    cin>>n;
    ll a,b,dp[nax];//max destroyed from left
    fr(i,0,nax){
        dp[i]=0;
        dist[i]=0;
    }
    for (int i = 0; i < n; ++i)
    {
        cin>>a>>b;
        dist[a]=b;
    }
    if(dist[0]>0)
        dp[0]=1;
    for (int i = 1; i < nax; ++i)
    {
        if(dist[i]==0)
            dp[i]=dp[i-1];
        else if(i-dist[i]>0)
            dp[i]=1+dp[i-dist[i]-1];
        else
            dp[i]=1;
        mx=max(mx,dp[i]);
    }
    cout<<n-mx<<endl;
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