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
vector<bool> vis;
ll a[nax],n,mx1=0,mx2=0,sz=0;
vector<ll> val;
void dfs(ll s){
    vis[s]=true;
    sz++;
    for(auto i : v[s]){
    	if(!vis[i] && val[i]==val[s])
    		dfs(i);
    }
}
void solve(){
	ll m,x,y;
	cin>>n>>m;
	v.resize(n+1);
	vis.resize(n+1,false);
	val.resize(n+1);
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
		val[i]=(__builtin_popcountll(a[i]))%2;
	}
	for (int i = 0; i < m; ++i)
	{
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	for (int i = 1; i <= n; ++i)
	{
		if(!vis[i]){
			dfs(i);
			if(val[i]%2)
				mx1=max(mx1,sz);
			else
				mx2=max(mx2,sz);
			sz=0;
		}
	}
	ll q;
	cin>>q;
	while(q--){
		ll type,k;
		cin>>type>>k;
		k=__builtin_popcountll(k);
		if(type==1){
			if(k%2){
				cout<<mx2<<endl;
			}
			else
				cout<<mx1<<endl;
		}
		else{
			if(k%2)
				cout<<mx1<<endl;
			else
				cout<<mx2<<endl;
		}
	}
	v.clear();
	vis.clear();
	val.clear();
	mx1=mx2=sz=0;
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
