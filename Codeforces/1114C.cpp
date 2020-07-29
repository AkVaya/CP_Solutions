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
vector<ll> factors;
map<ll,ll> ma;
void factorise(ll a){
    if(a%2==0){
            while(a%2==0){
                a/=2;
                ma[2]++;
            }
            factors.pb(2);
    }
    for(int i = 3; i <= sqrt(a); i+=2){
        if(a%i==0){
            while(a%i==0){
                a/=i;
                ma[i]++;    
            }
            factors.pb(i);
        }
    }
    if(a>1){
        factors.pb(a);
        ma[a]++;
    }
}
void solve(){ 
    ll n,m;
    cin>>n>>m;
    factorise(m);
    ll ans=inf;
    for(auto i : factors){
        //cout<<i<<" ";
        ll cnt=0;
        ll x = n;
        while(x){
            cnt+=x/i;
            x/=i;
        }
        //cout<<cnt<<" "<<ma[i]<<" ";
        cnt/=ma[i];
        //cout<<cnt<<endl;
        ans=min(ans,cnt);
    }
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