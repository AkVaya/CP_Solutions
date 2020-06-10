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
bool vis[500005];
ll level[500005];
vector<vector<int > > v;
vector<ll> vx;
void dfs(int source){
    if(vis[source])
        return;
    vis[source]=true;
    vx.pb(source);
    for (int i = 0; i < v[source].size(); ++i)
    {
        if(vis[v[source][i]])
            continue;
        dfs(v[source][i]);
    }
}
void solve(){
    ll n ,m;
    cin>>n>>m;
    memset(vis,false,sizeof(vis));
    v.resize(n+1);
    for (int i = 0; i < m; ++i)
    {
        ll x,grp;
        cin>>x;
        if(x>1){
            ll y;
            cin>>y;
            for (int j = 0; j < x-1; ++j)
            {
                cin>>grp;
                v[grp].pb(y);
                v[y].pb(grp);
            }
        }
        else if(x)
            cin>>x;
    }
    ll ans[n+1];   
    for (int i = 1; i <= n; ++i)
    {
        if(!vis[i]){
            vx.clear();
            dfs(i);
            //cout<<i<<" : ";
            for (int i = 0; i < vx.size(); ++i)
            {
                //cout<<vx[i]<<" ";
                ans[vx[i]]=vx.size();
            }
            //cout<<endl;

        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout<<ans[i]<<" ";
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