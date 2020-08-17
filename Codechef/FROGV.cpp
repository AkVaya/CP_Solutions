#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
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
vector<vector<ll> >v;
vector<ll> num;
ll n,p,k;
void dfs(ll s,ll clr){
	num[s]=clr;
	for(auto i : v[s]){
		dfs(i,clr);
	}
}
void solve(){
	ll x,y;
	cin>>n>>k>>p;
	v.resize(n+1);
	num.resize(n+1,-1);
	vector<pii> a;
	a.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i].first;
		a[i].second=i+1;
	}
	sort(a.begin(), a.end());
	for (int i = 1; i < n; ++i)
	{
		if(a[i].first-a[i-1].first<=k){
			ll fir=a[i-1].second;
			ll sec=a[i].second;
			v[fir].pb(sec);
		}
	}
	ll clr=1;
	for (int i = 1; i <= n; ++i){
		if(num[i]==-1)
			dfs(i,clr++);
	}
	while(p--){
		cin>>x>>y;
		if(num[x]==num[y])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;

	}
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