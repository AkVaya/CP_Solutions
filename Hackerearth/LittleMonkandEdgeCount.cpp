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
#define pf push_front
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
#define fr(i,a,b) for (int i = a; i < b; ++i)
using namespace std;
const ll M =1e9+7;
const ll nax=1e5+1;
vector<bool> vis;
vector<vector<ll> > v;
ll n,m,ans=0;
vector<ll> a;
vector<pair<ll,ll> > vp;
map<ll,ll> mpx;
ll dfs(ll s){
    vis[s]=true;
    ll cnt=1;
    for (int i = 0; i < v[s].size(); ++i)
    {
        if(!vis[v[s][i]]){
            cnt+=dfs(v[s][i]);
        }
    }
    mpx[s]=cnt;
    return cnt;
}
void solve(){
    cin>>n>>m;
    v.resize(n+1);
    a.resize(n+1);
    vis.resize(n+1);
    fill(vis.begin(), vis.end(),false);
    ll x,y;
    for (int i = 0; i < n-1; ++i)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
        vp.pb(mp(x,y));
    }
    x=dfs(1);
    //for (int i = 1; i <= n; ++i)
    //{
    //    cout<<mpx[i]<<endl;
    //}
    while(m--){
        cin>>x;
        pair<ll,ll>p=vp[x-1];
        ll a = p.first;
        ll b = p.second;
        ll ans=0;
        if(mpx[a]>mpx[b])
        {
            a = n-mpx[b];
            b= mpx[b];
            ans = (n*(n-1))/2 -(a*(a-1))/2 -(b*(b-1))/2;
        }
        else
        {
            b=n-mpx[a];
            a=mpx[a];
            ans = (n*(n-1))/2 - (a*(a-1))/2 - (b*(b-1))/2;
        }
        cout<<ans<<endl;
    }
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