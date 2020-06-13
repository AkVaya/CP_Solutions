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
//vector<bool> vis;
vector<vector<ll> > v;
/*void dfs(ll s){
    if(vis[s])
        return ;
    vis[s]=true;
    for (int i = 0; i < v[s].size(); ++i)
    {
        if(v[s][i])
            continue;
        dfs(v[s][i]);
    }
}*/
void solve(){
    ll n,x,y,m,ans=M;
    cin>>n>>m;
    v.resize(n+1);
    //vis.resize(n+1);
    ll a[nax][nax];
    memset(a,0,sizeof(a));
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y;
        a[x][y]=a[x][y]=1;
        v[x].pb(y);
        v[y].pb(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        for(auto j : v[i]){
            for (auto k: v[j])
            {
                //cout<<i<<" "<<j<<" "<<k<<endl;
                if(a[i][k]){
                    ll temp=v[i].size()+v[j].size()+v[k].size()-6;
                    ans=min(ans,(temp));
                }
            }
        }
    }
    if(ans==M)
        ans=-1;
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