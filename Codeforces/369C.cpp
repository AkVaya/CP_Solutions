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
vector<bool> exist;
vector<ll> cnt;
ll dfs(ll s,ll p){
    if(cnt[s]!=-1)
        return cnt[s];
    cnt[s]=exist[s];
    for (auto i : v[s])
    {
        if(i==p)
            continue;
        dfs(i,s);
        cnt[s]+=cnt[i];
    }
    return cnt[s];
}
void solve(){
    ll n,x,y,z;
    cin>>n;
    cnt.resize(n+1,-1);
    v.resize(n+1);
    exist.resize(n+1,0);
    for (int i = 0; i < n-1; ++i)
    {
        cin>>x>>y>>z;
        v[x].eb(y);
        v[y].eb(x);
        if(z-1)
            exist[x]=exist[y]=1;
    }
    dfs(1,1);
    vector<ll> ans;
    for (int i = 1; i <= n; ++i)
    {
        if(cnt[i]==1)
            ans.eb(i);
    }
    cout<<ans.size()<<endl;
    for(auto i : ans)
        cout<<i<<" ";
    cout<<endl;
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