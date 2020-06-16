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
const ll nax=2e5+1;
vector<bool> vis;
vector<vector<int > > v;
ll val,n;
vector<pair<ll,ll> > order;
map<pair<ll,ll>,ll> m;
void dfs(ll s,ll p){
    vis[s]=true;
    if(v[s].size()==1){
        m[mp(s,p)]=++val;
        m[mp(p,s)]=val;
        return; 
    }
    for (int i = 0; i < v[s].size(); ++i)
    {
        if(v[s][i]==p)
            continue;
        dfs(v[s][i],s);
    }
}
void solve(){
    ll n,x=0,y=0;
    cin>>n;
    v.resize(n+1);
    vis.resize(n+1);
    for (int i = 0; i < n-1; ++i)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
        order.pb(mp(x,y));
    }
    ll mx=0,ind=-1;
    for (int i = 1; i <= n; ++i)
    {
        if(mx<v[i].size()){
            mx=v[i].size();
            ind=i;
        }
    }
    ll val=-1;
    for (auto i : order)
    {
        if(i.second==ind || i.first==ind)
            m[i]=++val;
        else
            m[i]=-1;
    }
    for(auto i : order){
        if(m[i]==-1)
            cout<<++val<<endl;
        else
            cout<<m[i]<<endl;
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