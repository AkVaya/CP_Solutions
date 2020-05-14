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
vector<vector<ll> > v;
bool vis[100005];
ll dp[100005];
void dfs(int node){
	if(v[node].size()==0 || vis[node])
		return;
	vis[node]=true;
	for (int i = 0; i < v[node].size(); ++i)
	{
		if(!vis[v[node][i]])
			dfs(v[node][i]);
		dp[node]=max(dp[node],1+dp[v[node][i]]);
	}
}
void solve(){
	ll vertex,e,ans=0;
	cin>>vertex>>e;
	//cout<<0<<endl;
	v.resize(vertex+1);
	memset(vis,false,sizeof(vis));
	ll x,y;
	for (int i = 0; i <=vertex; ++i)
	{
		dp[i]=0;
	}
	//cout<<"1";
	for (int i = 0; i < e; ++i)
	{
		cin>>x>>y;
		v[x].pb(y);
	}
	//cout<<"2";
	for (int i = 1; i <=vertex; ++i)
	{
		if(!vis[i])
			dfs(i);
	}
	//cout<<"3";
	for (int i = 1; i <=vertex; ++i)
	{
		ans=max(ans,dp[i]);
	}
	cout<<ans;

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
