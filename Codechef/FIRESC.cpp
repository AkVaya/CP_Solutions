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
vector<bool> vis;
ll cnt=0;
void dfs(ll s){
	cnt++;
	vis[s]=true;
	for(auto i : v[s]){
		if(!vis[i]){
			dfs(i);
		}
	}
}
void mult(ll &a,ll b){
	a*=b;
	a%=M;
}
void solve(){
	ll n,m,x,y;
	cin>>n>>m;
	vis.resize(n+1,false);
	v.resize(n+1);
	for (int i = 0; i < m; ++i)
	{
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	ll temp=0,ans=1;
	for (int i = 1; i <= n; ++i)
	{
		if(!vis[i]){
			dfs(i);
			mult(ans,cnt);
			cnt=0;
			temp++;
		}
	}
	cout<<temp<<' '<<ans<<endl;
	v.clear();
	vis.clear();
	
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