#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<bitset>
#include<vector>
#include<iomanip>
#include<queue>
#define endl '\n'
#define Fir first
#define Sec second
#define pb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
#define LB lower_bound
#define UB upper_bound
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=1e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll n,cost[nax];
vector<vector<ll> > v,tempv;
vector<bool> vis;
stack<ll> st;
map<ll,ll> ma;
void dfs1(ll s){
    vis[s]=true;
    for(auto i : v[s])
        if(!vis[i])
            dfs1(i);
    st.push(s);
}
void dfs2(ll s){ 
    vis[s]=true;
    ma[cost[s]]++;
    for(auto i : tempv[s])
        if(!vis[i])
            dfs2(i);
}
void mult(ll &a,ll b){
    a*=b;
    a%=M;
}
void solve(){
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>cost[i+1];
    }
    ll val=0,cnt=1;
    ll m,x,y;
    v.resize(n+1);
    tempv.resize(n+1);
    vis.resize(n+1,false);
    cin>>m;
    while(m--){
        cin>>x>>y;
        v[x].pb(y);
        tempv[y].pb(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        if(!vis[i]){
            dfs1(i);
        }
    }
    fill(vis.begin(), vis.end(),false);
    while(st.size()){
        ll curr=st.top();
        if(!vis[curr]){
            dfs2(curr);
            auto j = ma.begin();
            val+=j->first;
            mult(cnt,j->second);
            ma.clear();
        }
        st.pop();
    }
    cout<<val<<" "<<cnt<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //#ifndef ONLINE_JUDGE 
      //  freopen("input.txt", "r", stdin); 
      //  freopen("output.txt", "w", stdout); 
    //#endif 

    //clock_t t3 = clock();
    ll t=1,t1=1;
    //cin>>t;
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}