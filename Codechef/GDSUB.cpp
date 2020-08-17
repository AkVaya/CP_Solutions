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
//#define endl '\n'
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
void add(ll &a,ll b){
	a+=b;
	a%=M;
}
ll mult(ll &a,ll b){
	a*=b;
	a%=M;
	return a;
}
void solve(){
	ll n,ans=0,k;
	cin>>n>>k;
	ll a[n];
	map<ll,ll> m;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		m[a[i]]++;
	}
	vector<ll> v;
	v.pb(0);
	for(auto i : m)
		v.pb(i.second);
	n=v.size();
	k=min(k,n);
	ll dp[v.size()][k+1];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (int i = 1; i < v.size(); ++i)
	{
		dp[i][0]=1;
		for (int j = 1; j <= k; ++j)
		{
			dp[i][j]=dp[i-1][j];
			add(dp[i][j],mult(dp[i-1][j-1],v[i]));
		}
	}
	for (int i = 0; i <= k; ++i)
	{
		add(ans,dp[v.size()-1][i]);
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