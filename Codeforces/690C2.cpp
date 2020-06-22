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
vector<vector<int > > v;
vector<ll> dep;
void dfs(ll s,ll p){
    //cout<<s<<" "<<dep[s]<<endl;
    for (int i = 0; i < v[s].size(); ++i)
    {
        if(v[s][i]==p)
            continue;

        dep[v[s][i]]=1 + dep[s];
        dfs(v[s][i],s);
    }
}
void solve(){
    ll n,x,y,m;
    cin>>n>>m;
    v.resize(n+1);
    dep.resize(n+1,-1);
    //vis.resize(n+1,false);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    ll ans=0;
    dep[1]=0;
    dfs(1,1);
    ll ind=0;
    for (int i = 1; i <= n; ++i)
    {
        if(ans<dep[i]){
            ans=dep[i];
            ind=i;
        }
        //cout<<dep[i]<<" ";
        dep[i]=-1;
    }
    dep[0]=0;
    dep[ind]=0;
    dfs(ind,ind);
    cout<<*max_element(dep.begin(),dep.end())<<endl;
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