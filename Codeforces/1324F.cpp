#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<iomanip>
#include<queue>
#define pb push_back
#define Fir first
#define Sec second
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll ;
const ll M =998244353;
const ll nax=2e5+5;
const ll inf=9e18;
using pii = pair<ll,ll>;
ll n,a[nax],ans[nax],dp[nax];// 0 for black
vector<vector<ll> > v;
ll dfs(ll s,ll p){
    dp[s]=0;
    if(a[s])
        dp[s]++;
    else
        dp[s]--;
    for (auto j : v[s])
    {
        if(j==p)
            continue;
        ll temp=dfs(j,s);
        if(temp>=0)
            dp[s]+=temp;
    }
    return dp[s];
}
void dfs1(ll s,ll p,ll last){
    ans[s]=dp[s]+last;
    for(auto i : v[s]){
        if(i==p)
            continue;
        dfs1(i,s,max(0LL,ans[s]-max(0LL,dp[i])));
    }
}
void solve(){
    cin>>n;
    ll x,y;
    v.resize(n+1);
    for (int i = 1; i < n+1; ++i)
    {
        cin>>a[i];
    }
    for (int i = 1; i < n; ++i)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    x=dfs(1,1);
    dfs1(1,1,0);
    for (int i = 1; i <= n; ++i)
    {
        cout<<ans[i]<<" ";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //#ifndef ONLINE_JUDGE 
      //  freopen("input.txt", "r", stdin); 
      //  freopen("output.txt", "w", stdout); 
    //#endif 

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