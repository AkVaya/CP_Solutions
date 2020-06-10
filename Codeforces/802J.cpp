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
const ll nax=1e4+1;
vector<bool> vis;
vector<vector<pair<ll,ll> > > v;
vector<ll> vx;
ll dfs(ll source, ll cost){
    if(vis[source])
        return 0;
    vis[source]=true;
    ll temp=cost;
    for (int i = 0; i < v[source].size(); ++i)
    {
        if(!vis[v[source][i].first]){
            //cout<<"Next: "<<v[source][i].first<<" Cost till now: "<<temp<<" ";
            ll x=dfs(v[source][i].first,temp+v[source][i].second);
            cost=max(cost,x);
            //cout<<x<<endl;
        }

    }
    return cost;
}
void solve(){
    ll n ,m,x,y,c;
    cin>>n;
    vis.resize(n);
    fill(vis.begin(), vis.end(),false);
    v.resize(n);
    for (int i = 0; i < n-1; ++i)
    {
        cin>>x>>y>>c;
        v[x].pb(mp(y,c));
        v[y].pb(mp(x,c));
    }
    ll ans=0;
    for (int i = 0; i < n; ++i)
    {
        if(!vis[i]){
            ll x=dfs(i,0);
            ans=max(x,ans);
            //cout<<x<<endl;
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