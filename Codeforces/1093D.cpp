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
const ll nax=3e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
vector<vector<ll> > v;
vector<bool> vis;
vector<ll> val;
bool check=true;
ll binpow(ll a,ll b,ll m=M) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = ((res%m) * (a%m)) % m;
        a = ((a%m) * (a%m)) % m;
        b >>= 1;
    }
    return res;
}
map<ll,ll> ma;
void dfs(ll s,ll flip){
	vis[s]=true;
	ma[flip]++;
	val[s]=flip;
	if(!v[s].size())
		val[s]=3;
	for (auto i : v[s])
	{
		if(!vis[i])
			dfs(i,1-flip);
		else if(val[i]==flip)
			check=false;
	}
}
void mult(ll &a,ll b){
	a*=b;
	a%=M;
}
void add(ll &a,ll b){
	a+=b;
	a%=M;
}
void solve(){
	ll n,m,x,y;
	cin>>n>>m;
	v.resize(n+1);
	val.resize(n+1,-1);
	vis.resize(n+1,false);
	for (int i = 0; i < m; ++i)
	{
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	ll num1=0,num2=0,num3=0;
	ll ans=1;
	for (int i = 1; i <= n; ++i)
	{
		if(v[i].size()==0){
			num3++;
			continue;
		}
		else if(!vis[i]){
			dfs(i,0);
			ll temp1=binpow(2,ma[0]);
			ll temp2=binpow(2,ma[1]);
			//cout<<temp1<<' '<<temp2<<' '<<ma[0]<<' '<<ma[1]<<endl;
			add(temp1,temp2);
			//cout<<temp1<<endl;
			mult(ans,temp1);
			ma.clear();
		}
	}	if(!check)
		cout<<0<<endl;
	else{
		mult(ans,binpow(3,num3));
		cout<<ans<<endl;
	}
	vis.clear();
	val.clear();
	v.clear();
	check=true;
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