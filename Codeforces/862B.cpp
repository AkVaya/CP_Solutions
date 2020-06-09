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
const ll nax=1e5+1;
bool vis[nax];
ll level[nax];
vector<vector<int > > v;
void dfs(int source){
    if(vis[source])
        return;
    vis[source]=true;
    for (int i = 0; i < v[source].size(); ++i)
    {
        if(vis[v[source][i]])
            continue;
        level[v[source][i]]=1+level[source];
        dfs(v[source][i]);
    }
}
void solve(){
    ll n;
    cin>>n;
    v.resize(n+1);
    ll x,y;
    for (int i = 0; i < n-1; ++i)
    {
        cin>>x>>y;
        v[y].pb(x);
        v[x].pb(y);
    }
    ll ans=0;
    level[1]=1;
    dfs(1);
    for (int i = 1; i <= n; ++i)
    {
        if(level[i]%2==0){
            ans++;
        }
    }
    cout<<(ans*(n-ans))-(n-1)<<endl;
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