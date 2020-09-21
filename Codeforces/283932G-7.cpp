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
#include<iomanip>
//#define endl '\n'
#include<bits/stdc++.h>
#define pb push_back
#define ins insert 
#define Fir first
#define Sec second
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
using namespace std;
typedef long long ll ;
using pii = pair<ll,ll>;
const ll M =1e9+7;
const ll nax=2e5+69;
ll k,n;
ll a[nax];
bool fun(ll x){
	ll total = x*k;
	for (int i = 0; i < n; ++i)
	{
		total -= min(a[i],x);
	}
	return total<=0;
}
void solve(){
	cin>>k>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	ll l = 0, r = n*1e9;
	while(l<=r){
		ll mid = (l+r)/2;
		if(fun(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	cout<<l-1<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    //cin>>t;
    //clock_t t3 = clock();
    while(t--){
    //    cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
   // cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
   // cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}