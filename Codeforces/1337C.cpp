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
vector<bool>vis;
vector<vector<int > > v;
vector<ll> ans;
ll dfs(ll s,ll p,ll val){
    vis[s]=true;
    ll cnt=1;
    for (int i = 0; i < v[s].size(); ++i)
    {
        if(v[s][i]==p)
            continue;
        cnt+=dfs(v[s][i],s,val+1);
    }
    //cout<<s<<" "<<cnt<<" "<<val<<endl;
    ans.pb(cnt-val-1);
    return cnt;
}
void solve(){
    ll n,x,y,k;
    cin>>n>>k;
    v.resize(n+1);
    vis.resize(n+1);
    for (int i = 0; i < n-1; ++i)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    x=dfs(1,1,0);
    x=0;
    sort(ans.begin(), ans.end(),greater<int>());
    for (int i = 0; i < n-k; ++i)
    {
        x+=ans[i];
    }
    cout<<x<<endl;
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