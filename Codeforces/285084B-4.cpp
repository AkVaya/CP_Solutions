#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<bitset>
#include<iomanip>
#include<queue>
#define endl '\n'
#define pb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=1e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll n,d;
ll fun(ll val){
	ll cnt=0;
	for (int i = 1; i <= n; ++i)
	{
		if(val%i)
			cnt+=min(val/i,n);
		else
			cnt+=min(val/i-1,n);
	}
	//cout<<val<<' '<<cnt<<endl;
	return cnt;
}
void solve(){
    cin>>n>>d;
    d--;
    /*vector<ll> v;
    for (int i = 1; i <= n; ++i)
    {
    	for (int j = 1; j <= n; ++j)
    	{
    		v.pb(i*j);
    	}
    }
    sort(v.begin(), v.end());
    cout<<v[d]<<endl;
    */
    ll l = 1, r = 1e10;
    while(l<=r){
    	ll mid = (l+r)/2;
    	ll temp = fun(mid);
    	if(temp<=d)
    		l = mid+1;
    	else 
    		r = mid-1;
    //	cout<<l<<' '<<r<<endl;
    }
    cout<<l-1<<endl;
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
