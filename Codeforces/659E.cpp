#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<queue>
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=1e5+5;
const ll inf=1e18;
using pii = pair<ll,ll>;
vector<bool>vis;
vector<vector<ll> > v;
ll e=0,ver=0;
void dfs(ll s){
    vis[s]=true;
    ver++;
    e+=v[s].size();
    for (auto i : v[s])
    {
        if(vis[i])
            continue;
        dfs(i);
    }
}
void solve(){
    ll n,x,y,z,m,ans=0;
    cin>>n>>m;
    vis.resize(n+1,false);
    v.resize(n+1);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y;
        v[x].eb(y);
        v[y].eb(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        if(!vis[i]){
            dfs(i);
            e/=2;
            //cout<<e<<" "<<ver<<endl;
            if(e==ver-1)
                ans++;
            e=0;
            ver=0;
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