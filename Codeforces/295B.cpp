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
const ll nax=569;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
void solve(){
    ll n;
    cin>>n;
    ll d[n+1][n+1];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin>>d[i+1][j+1];
        }
    }
    vector<ll>ans,b(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>b[i];
    }
    reverse(b.begin(), b.end());
    for (int k = 1; k <= n; ++k) {
        ll curr=b[k-1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if(i==j)
                    continue;
                d[i][j] = min(d[i][j], d[i][curr] + d[curr][j]); 
            }
        }
        ll val=0;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if(i==j)
                    continue;
                val+=d[b[i]][b[j]];
            }
        }
        ans.pb(val);
    }
    reverse(ans.begin(), ans.end());
    for(auto i : ans)
        cout<<i<<" ";
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