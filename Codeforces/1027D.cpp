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
const ll M =998244353;
const ll nax=2e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
vector<vector<ll> > v;
vector<ll> vis;
vector<vector<ll> >cycles;
vector<ll> to;
void dfs(ll s){
	to.pb(s);
	vis[s]=1;
	//cout<<s<<' ';
	for(auto i : v[s]){
		if(vis[i]==-1)
			dfs(i);
		else if(vis[i]==1){
			vector<ll> temp;
			ll ind=to.size()-1;
			while(to[ind]!=i)
				temp.pb(to[ind--]);
			temp.pb(i);
			cycles.pb(temp);
		}
	}
	//cout<<endl;
	vis[s]=2;
}
void solve(){
	ll n,x;
	cin>>n;
	v.resize(n+1);
	vis.resize(n+1,-1);
	ll ans=0;
	ll cost[n+1];
	for (int i = 1; i <= n; ++i)
	{
		cin>>cost[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin>>x;
		v[i].pb(x);
	}
	for (int i = 1; i <= n; ++i)
	{
		if(vis[i]==-1){
			dfs(i);
		}
	}
	for(auto j : cycles){
		ll mn=cost[j[0]];
		for (int i = 1; i < j.size(); ++i)
		{
			//cout<<j[i]<<' ';
			mn=min(cost[j[i]],mn);
		}
		//cout<<endl;
		ans+=mn;
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