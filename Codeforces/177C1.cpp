#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stdio.h>
#include<iomanip>
#include<bitset>
#include<algorithm>
#include<map>
#include<math.h>
#include<cstring>
#include<string>
#include<ctime>
#include<cmath>
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
#define fr(i,a,b) for (int i = a; i < b; ++i)
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=2e6+10;
vector<vector<ll> > l,dl;
vector<bool> vis;
set<ll> se;
bool dfs(ll s){
    se.ins(s);
    vis[s]=true;
    bool x=true;
    for (auto i : l[s])
    {
        //cout<<i<<endl;
        if(!vis[i])
            x&=dfs(i);
    }
    for (auto i : dl[s])
    {
        if(se.find(i)!=se.end()){
            x=false;
        }
    }
    return x;
}
void solve(){
    ll n,x,y,m;
    cin>>n>>m;
    l.resize(n+1);
    dl.resize(n+1);
    vis.resize(n+1,false);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y;
        l[x].pb(y);
        l[y].pb(x);
    }
    ll ans=0;
    cin>>m;
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y;
        dl[x].pb(y);
        dl[y].pb(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        //cout<<i<<endl;
        if(!vis[i]){
            if(dfs(i)){
                ans=max(ans,(ll)se.size());
                //cout<<i<<" "<<ans<<endl;
            }

        }
        se.clear();
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