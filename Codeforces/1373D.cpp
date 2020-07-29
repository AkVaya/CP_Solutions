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
void solve(){ 
    ll n;
    cin>>n;
    ll a[n],dp[n+1][3];
    memset(dp,0,sizeof(dp));
    for(int i = 0; i < n; ++i){
        cin>>a[i];
    }
    for(int i = 0; i < n; ++i){
        dp[i+1][0]= (i%2 ? 0 : a[i]) + dp[i][0];
        if(i+2<=n)
            dp[i+2][1]= max(dp[i][1],dp[i][0])+(i%2 ? a[i] : a[i+1] );
        dp[i+1][2]=max3(dp[i][0],dp[i][1],dp[i][2])+ (i%2 ? 0 : a[i]);
        //cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
    }
    cout<<max3(dp[n][0],dp[n][1],dp[n][2])<<endl;
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