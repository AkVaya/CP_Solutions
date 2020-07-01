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
const ll nax=2e6+5;
const ll inf=1e18;
using pii = pair<ll,ll>; 
void solve(){
    ll n,k;
    map<ll,ll> m;
    cin>>n>>k;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        if(a[i]%k)
            m[k-a[i]%k]++;
    }
    ll mx=0;
    for(auto i : m ){
        //cout<<i.first<<" "<<i.second<<endl;
        mx=max(i.first + (i.second-1)*k,mx);
    }
    if(mx)
        mx++;
    cout<<mx<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //#ifndef ONLINE_JUDGE 
      //  freopen("input.txt", "r", stdin); 
      //  freopen("output.txt", "w", stdout); 
    //#endif 
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