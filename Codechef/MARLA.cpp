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
const ll nax=1e3+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll n,m;
ll a[nax][nax];
bool vis[nax][nax];
pii ans={inf,0LL};// first is val, second is cnt
void fun(ll a,ll b){
	if(b>ans.second){
		ans.first=a;
		ans.second=b;
	}
	else if(b==ans.second){
		if(ans.first>a)
			ans.first=a;
	}
}
ll dfs(ll i,ll j,ll val){
	ll cnt=1;
	vis[i][j]=true;
	if(i>0 && a[i-1][j]==val && !vis[i-1][j]) 
		cnt+=dfs(i-1,j,val);
	if(j>0 && a[i][j-1]==val && !vis[i][j-1]) 
		cnt+=dfs(i,j-1,val);
	if(i<n-1 && a[i+1][j]==val && !vis[i+1][j]) 
		cnt+=dfs(i+1,j,val);
	if(j<m-1 && a[i][j+1]==val && !vis[i][j+1]) 
		cnt+=dfs(i,j+1,val);
	return cnt;
}
void solve(){
	cin>>n>>m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>a[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(!vis[i][j]){
				fun(a[i][j],dfs(i,j,a[i][j]));
			}
		}
	}
	cout<<ans.first<<' '<<ans.second<<endl;
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