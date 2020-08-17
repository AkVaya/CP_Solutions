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
const ll nax=2e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
vector<vector<ll> > v;
vector<bool> vis;
vector<ll>side;
void dfs(ll s,ll flip){
	vis[s]=true;
	side[s]=flip;
	for(auto i : v[s]){
		if(!vis[i])
			dfs(i,1-flip);
	}
}
void solve(){
	ll n,m,x,y;
	cin>>n>>m;
	side.resize(n+1,-1);
	v.resize(n+1);
	vis.resize(n+1,false);
	for (int i = 0; i < m; ++i)
	{
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,1);
	vector<ll> temp1,temp2;
	for (int i = 1; i <= n; ++i)
	{
		if(side[i])
			temp1.pb(i);
		else
			temp2.pb(i);
	}
	if(temp1.size()<=n/2){
		cout<<temp1.size()<<endl;
		for(auto i : temp1)
			cout<<i<<' ';
		cout<<endl;
	}
	else{
		cout<<temp2.size()<<endl;
		for(auto i : temp2)
			cout<<i<<' ';
		cout<<endl;
	}
	vis.clear();
	v.clear();
	side.clear();
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