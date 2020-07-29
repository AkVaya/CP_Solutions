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
//#define endl '\n'
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
// find_by_order(k): returns an iterator to the kth largest element (0-base)
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
typedef long long ll ;
const ll M =1e9+7;
const ll nax=1e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
void solve(){ 
    ll n,m,x,y;
    cin>>n>>m;
    vector<vector<ll> > v;
    v.resize(n+1);
    vector<pii> edges;
    vector<ll> val(n+1,0);
    for(int i = 0; i < m ; ++i){
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
        edges.pb(mp(x,y));
    }
    for(int i = 1; i <= n ; ++i){
        cin>>val[i];
    }
    for(auto i : edges){
        if(val[i.first]==val[i.second]){
            cout<<-1<<endl;
            return;
        }
    }
    for(int i = 1; i <= n; ++i){
        set<ll> s;
        for(auto j : v[i]){
            s.ins(val[j]);
        }
        ll curr=1;
        for(auto j : s){
            if(j==curr)
                curr++;
            if(curr>val[i]){
                cout<<-1<<endl;
                return;
            }
        }
        if(curr!=val[i]){
            cout<<-1<<endl;
            return;
        }
    }
    map<ll,set<ll> > ma;
    for(int i = 1; i <= n; ++i){
        ma[val[i]].ins(i);
    }
    for(auto i : ma){
        for(auto j : i.second)
            cout<<j<<" ";
    }
    cout<<endl;
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