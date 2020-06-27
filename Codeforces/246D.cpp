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
ll a[nax],n;
void dfs(ll s){
    if(vis[s])
        return;
    vis[s]=true;
    for (auto i : v[s])
    {
        if(vis[i])
            continue;
        dfs(i);
    }
}
void solve(){
    cin>>n;
    ll m,x,y,ans=inf,mx=0;
    cin>>m;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        ans=min(ans,a[i]);
    }
    v.resize(n);
    set<ll> s[nax];
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y;
        x--;y--;
        if(a[x]!=a[y]){
            s[a[x]].ins(a[y]);
            s[a[y]].ins(a[x]);
        }
    }
    for(int i = 1 ; i < nax ; ++i){
        if(s[i].size()>mx){
            mx=s[i].size();
            ans = i;
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