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
string t,p;
ll a[nax],n;
bool fun(ll x){
	vector<ll> v(n,1);
	for (int i = 0; i < x; ++i)
	{
		v[a[i]]=0;
	}
	ll ind = 0;
	for (int i = 0; i < n; ++i)
	{
		if(v[i] && t[i]==p[ind])
			ind++;
	}
	return ind==p.length();
}
void solve(){
	cin>>t>>p;
	n = t.length();
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		a[i]--;
	}
	ll l = 0, r = n;
	while(l<=r){
		ll mid = (l+r)/2;
		if(fun(mid)){
			l = mid + 1;
		}
		else r = mid - 1;
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