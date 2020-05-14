#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 10000007
#define inf 1000000000000000000
using namespace std;
void solve(){
	ll n,w;
	cin>>n>>w;
	ll we[n],v[n],maxv=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>we[i]>>v[i];
		maxv+=v[i];
	}
	ll dp[maxv+1];
	for (int i = 1; i <=maxv; ++i)
	{
		dp[i]=inf;
	}
	dp[0]=0;
	for (int i = 1; i <=n; ++i)
	{
		ll x=v[i-1];
		for (int j = maxv; j>=x; --j)
		{
			dp[j]=min(dp[j],dp[j-x]+we[i-1]);
		}
	}
	for (int i = maxv; i >=0; --i)
	{
		if(dp[i]<=w){
			cout<<i;
			break;
		}
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0 ;
}
