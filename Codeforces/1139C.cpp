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
ll cnt=0;
void dfs(int source){
    if(vis[source])
        return;
    vis[source]=true;
    cnt++;
    for (int i = 0; i < v[source].size(); ++i)
    {
        if(vis[v[source][i]])
            continue;
        dfs(v[source][i]);
    }
}
long long binpow(long long a, long long b, long long m=M) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = ((res%m) * (a%m)) % m;
        a = ((a%m) * (a%m)) % m;
        b >>= 1;
    }
    return res;
}
void solve(){
    ll n,m,x,y,ans=0,k;
    cin>>n>>k;
    v.resize(n+1);
    vis.resize(n+1);
    for (int i = 0; i < n-1; ++i)
    {
        cin>>x>>y>>m;
        if(!m){
            v[x].pb(y);
            v[y].pb(x);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if(!vis[i]){
            dfs(i);
            ans+=(binpow(cnt,k));
            cnt=0;
        }
    }
    ans = (binpow(n,k))-ans;
    while(ans<0)
        ans+=M;
    ans%=M;
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