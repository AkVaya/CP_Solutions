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
const ll nax=5e5+1;
vector<bool> vis;
vector<vector<pair<ll,ll> > > v;
bool dfs(ll source,ll destination, ll color){
    if(source==destination)
        return true;
    vis[source]=true;
    for (int i = 0; i < v[source].size(); ++i)
    {
        if(!vis[v[source][i].first] && v[source][i].second==color){
            if(dfs(v[source][i].first,destination,color))
                return true;
        }

    }
    return false;
}
void solve(){
    ll n ,m,x,y,c;
    cin>>n>>m;
    vis.resize(n+1);
    fill(vis.begin(), vis.end(),false);
    v.resize(n+1);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y>>c;
        v[x].pb(mp(y,c));
        v[y].pb(mp(x,c));
    }
    ll q,u,v;
    cin>>q;
    while(q--){
        ll ans=0;
        cin>>u>>v;
        for (int i = 1; i <= 100; ++i)
        {
            if(dfs(u,v,i))
                ans++;
            //cout<<ans<<" ";
            fill(vis.begin(), vis.end(),false);
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