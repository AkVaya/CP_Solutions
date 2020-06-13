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
const ll M =1e9+7;
const ll nax=4e3+1;
vector<bool> vis;
vector<vector<ll> > v;
set<ll> se;
ll edges=0;
ll dfs(ll s){
    vis[s]=true;
    ll cnt=1;
    edges+=v[s].size();
    for (int i = 0; i < v[s].size(); ++i)
    {
        if(vis[v[s][i]])
            continue;
        cnt+=dfs(v[s][i]);
    }
    return cnt;
}
void solve(){
    ll n,x,y,m,k,ans=0;
    cin>>n>>m>>k;
    v.resize(n+1);
    vis.resize(n+1);
    ll a[n+1];
    for (int i = 0; i < k; ++i)
    {
        cin>>x;
        se.ins(x);
    }
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    ll mx=0;
    for(auto i : se){
        if(!vis[i])
            a[i]=dfs(i);
        //cout<<i<<" : "<<a[i]<<endl;
        ll temp=((a[i]-1)*a[i])/2 - edges/2;
        edges=0;
        ans+=temp;
        mx=max(mx,a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        if(!vis[i]){
            ll temp = dfs(i);
            ans+=mx*temp;
            ans+=(((temp-1)*temp)/2 - edges/2);
            mx+=temp;
            edges=0;
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