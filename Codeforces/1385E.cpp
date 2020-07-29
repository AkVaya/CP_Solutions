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
#include<unordered_set>
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
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
typedef long long ll ;
const ll M =1e9+7;
const ll nax=1e7+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
vector<bool> vis;
vector<vector<ll> > v;
vector<ll> topo;
void dfs(ll s){
    vis[s]=true;
    for(auto i : v[s]){
        if(!vis[i]){
            dfs(i);
        }    
    }
    topo.pb(s);
}
void solve(){ 
    ll n,m;
    cin>>n>>m;
    ll type,x,y;
    vector<pii> edges;
    bool check=false;
    v.clear();
    v.resize(n+1);
    vis.clear();
    vis.resize(n+1,false);
    for (int i = 0; i < m; ++i)
    {
        cin>>type>>x>>y;
        if(type==1){
            v[x].pb(y);
        }
        edges.pb(mp(x,y));
    }
    //cout<<endl;
    for (int i = 1; i <= n; ++i)
    {
        if(!vis[i]){
            dfs(i);
        }
        if(check)
            break;
    }
    vector<ll> loc(n+1,0);
    reverse(topo.begin(), topo.end());
    for (int i = 0; i < n; ++i)
    {
        loc[topo[i]]=i;
    }
    //cout<<endl;
    //for(auto i : topo){
    //    cout<<i<<" ";
    //}
    //cout<<endl;
    topo.clear();
    for (int i = 1; i < n+1; ++i)
    {
        for(auto j : v[i])
            if(loc[i]>loc[j]){
                check=true;
                break;
            }
    }

    if(check)
        cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(auto i : edges){
            if(loc[i.first]>loc[i.second])
                cout<<i.second<<" "<<i.first<<endl;
            else
                cout<<i.first<<" "<<i.second<<endl;
        }
    }
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
    cin>>t;
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}