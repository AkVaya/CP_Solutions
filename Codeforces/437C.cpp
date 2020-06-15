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
const ll nax=1e3+1;
vector<vector<ll> > v;
void solve(){
    ll n,m;
    cin>>n>>m;
    ll x,y;
    v.resize(n+1);
    vector<pair<ll,ll> > val;
    for (int i = 0; i < n; ++i)
    {
        cin>>x;
        val.pb({x,i+1});
    }
    sort(val.begin(), val.end());
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    ll ans=0;
    for (int i = 0; i < val.size(); ++i)
    {
        for (int j = 0; j < v[val[i].second].size(); ++j)
        {
            if(v[v[val[i].second][j]].size())
                ans+=val[i].first;
        }
        v[val[i].second].clear();
    }
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