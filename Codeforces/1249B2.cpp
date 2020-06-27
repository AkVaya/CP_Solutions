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
const ll inf=1e18;
using pii = pair<ll,ll>;
vector<vector<ll> > v;
vector<ll> ans,y;
vector<bool> vis;
ll cnt=0;
void dfs(int s){
    y.pb(s);
    cnt++;
    vis[s]=true;
    for (auto i : v[s])
    {
        if(vis[i])
            continue;
        dfs(i);
    }
}
void solve(){
    ll n,x;
    cin>>n;
    v.resize(n+1);
    ans.resize(n+1,0);
    vis.resize(n+1,false);
    for (int i = 1; i <= n; ++i)
    {
        cin>>x;
        v[i].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        if(!vis[i]){
            dfs(i);
            for(auto j : y)
                ans[j]=cnt;
            cnt=0;
            y.clear();
        }
    }
    for (int i = 1; i <= n; ++i)
        cout<<ans[i]<<" ";
    cout<<endl;
    v.clear();
    ans.clear();
    vis.clear();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    cin>>t;
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