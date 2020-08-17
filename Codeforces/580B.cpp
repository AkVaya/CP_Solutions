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
const ll nax=3e6+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
void solve(){
	ll n,d,ans=0;
	cin>>n>>d;
	vector<pii> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i].first>>v[i].second;
	}
	sort(v.begin(), v.end());
	vector<ll> pref(n+1,0);
	ll mon[n];
	for (int i = 0; i < n; ++i)
	{
		pref[i+1]=pref[i]+v[i].second;
		mon[i]=v[i].first;
	}
	for (int i = 0; i < n; ++i)
	{
		ll ind = lower_bound(mon,mon+n,mon[i]+d)-mon;
		ll curr = pref[ind]-pref[i];
		ans=max(ans,curr);
		//cout<<i<<' '<<ind<<' '<<curr<<endl;
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
