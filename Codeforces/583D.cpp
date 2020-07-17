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
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=2e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll dp[301],loc[301];//ending at i
void solve(){
    ll n,t,x;
    cin>>n>>t;
    ll mx=0;
    map<ll,ll> m;
    vector<ll> v(n*min(n,t));
    for (int i = 0; i < n; ++i)
    {
        cin>>v[i];
        m[v[i]]++;
    }
    memset(loc,M,sizeof(loc));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < min(n,t); ++j)
        {
            v[n*j+i]=v[i];
        }
    }
    for (int i = 0; i < v.size(); ++i)
    {
        ll temp=*max_element(dp,dp+v[i]+1);
        dp[v[i]]=max(dp[v[i]],1+temp);

    }
    ll ans=(t-min(n,t));
    for(auto i : m)
        mx=max(mx,i.second);
    ans*=mx;
    ans+=*max_element(dp,dp+301);
    cout<<ans<<endl;
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