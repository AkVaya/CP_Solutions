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
vector<pair<pii,pii> > v;
ll m,n;
ll cnt[nax];
bool fun(ll a){
	ll count = 0;
	for (int i = 0; i < n; ++i)
	{
		ll x = a / (v[i].first.first*v[i].second.first + v[i].second.second);
		//cout<<a<<':';
		ll y = a%(v[i].first.first*v[i].second.first + v[i].second.second);
		x*=v[i].second.first;
		//cout<<a<<endl;
		if(y>=v[i].first.first*v[i].second.first){
		//	cout<<"YAHA ";
			x+=v[i].second.first;
		}
		else{
		//	cout<<"VAHA ";
			x+=y/v[i].first.first;
		}
		cnt[v[i].first.second]=x;
		count+=x;
		//cout<<i<<' '<<x<<' '<<count<<endl;
	}
	return count>=m;
}
void calc(ll a){
	ll count = 0;
	ll ind = -1;
	for (int i = 0; i < n; ++i)
	{
		ll x = a / (v[i].first.first*v[i].second.first + v[i].second.second);
		ll y = a%(v[i].first.first*v[i].second.first + v[i].second.second);
		x*=v[i].second.first;
		if(y>=v[i].first.first*v[i].second.first){
			x+=v[i].second.first;
		}
		else{
			x+=y/v[i].first.first;
		}
		//cout<<i<<' '<<x<<endl;
		if(count+x<=m)
			cnt[v[i].first.second]=x;
		else{
			cnt[v[i].first.second]=m-count;
			ind = i+1;
			break;
		}
		count+=x;
		//cout<<i<<' '<<x<<' '<<count<<endl;
	}
	if(ind!=-1){
		for (int i = ind; i < n; ++i)
		{
			cnt[v[i].first.second]=0;
		}
	}
	
}
void solve(){
	cin>>m>>n;
	ll x,y,z;
	for (int i = 0; i < n; ++i)
	{
		cin>>x>>y>>z;
		v.pb({{x,i},{y,z}});
	}
	sort(v.begin(), v.end());
	ll l = 0, r = 1e6;
	while(l<=r){
		//cout<<l<<' '<<r<<endl;
		ll mid = (l+r)/2;
		if(fun(mid)){
			r = mid - 1;
		}
		else 
			l = mid + 1;
	}
	cout<<l<<endl;
	calc(l);
	for (int i = 0; i < n; ++i)
	{
		cout<<cnt[i]<<' ';
	}
	cout<<endl;
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