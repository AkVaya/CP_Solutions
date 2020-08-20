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
const ll nax=2e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
vector<vector<ll> >v;
vector<ll> parent,a;
ll n;
bool vis[nax][2];
vector<bool> check;
void dfs1(ll s,ll p,ll flip,ll origin){
	if(flip && s!=origin){
		a[origin]+=a[s];
		a[s]=0;
	}
	if(!vis[s][flip]){
		for(auto i : v[s]){
			if(i!=parent[s])
				dfs1(i,s,1-flip,origin);
		}
	}
	vis[s][flip]=true;
}
void dfs(ll s,ll p){
	parent[s]=p;
	for(auto i : v[s]){
		if(i!=p)
			dfs(i,s);
	}
}
void solve(){
	ll q,x,y;
	cin>>n>>q;
	a.resize(n+1);
	v.resize(n+1);
	parent.resize(n+1,1);
	for (int i = 1; i <= n; ++i)
	{
		vis[i][0]=vis[i][1]=false;
		cin>>a[i];
	}
	for (int i = 0; i < n-1; ++i)
	{
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,-1);
	while(q--){
		cin>>x;
		if(vis[x][1])
			continue;
		dfs1(x,parent[x],1,x);
	}
	for (int i = 1; i <= n; ++i)
	{
		cout<<a[i]<<' ';
	}
	cout<<endl;
	v.clear();
	a.clear();
	parent.clear();

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
