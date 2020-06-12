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
const ll nax=1e5+1;
vector<bool> vis;
vector<vector<ll> > v;
vector<ll> val;// val is the number of elements below this vertex including this vertex
void dfs(ll s,ll p){
    vis[s]=true;
    ll cnt = 1;
    for (int i = 0; i < v[s].size(); ++i)
    {
        if(v[s][i]==p)
            continue;
        dfs(v[s][i],s);
        cnt+=val[v[s][i]];
    }
    cnt%=2;
    val[s]=cnt;
}
void solve(){
    ll n,x,y,ans=0;
    cin>>n;
    v.resize(n+1);
    val.resize(n+1);
    vis.resize(n+1);
    for (int i = 0; i < n-1; ++i)
    {
        val[i]=-1;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    val[n-1]=-1;
    val[n]=-1;
    if(n%2){
        cout<<-1;
        return ;
    }
    dfs(1,1);
    for (int i = 1; i <= n; ++i)
    {
       // cout<<val[i]<<" ";
        ans+=(1-val[i]);
    } 
    ans--; // here ans is the number of components int the graph with even size(i.e edges)
    cout<<ans<<endl;// hence removed edges =ans-1
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