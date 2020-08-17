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
const ll nax=5e2+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll n,m,k,cnt=0;
char a[nax][nax];
bool vis[nax][nax];
ll curr=0;
void dfs(ll x,ll y){
	curr++;
	vis[x][y]=true;
	//cout<<x<<' '<<y<<' '<<curr<<endl;
	if(curr>=cnt-k)
		return;
	if(x<n-1 && a[x+1][y]=='.' && !vis[x+1][y])
		dfs(x+1,y);
	if(curr>=cnt-k)
		return;
	if(x>0 && a[x-1][y]=='.' && !vis[x-1][y])
		dfs(x-1,y);
	if(curr>=cnt-k)
		return;
	if(y>0 && a[x][y-1]=='.' && !vis[x][y-1])
		dfs(x,y-1);
	if(curr>=cnt-k)
		return;
	if(y<m-1 && a[x][y+1]=='.' && !vis[x][y+1])
		dfs(x,y+1);
	if(curr>=cnt-k)
		return;
}
void solve(){
	cin>>n>>m>>k;
	ll x,y;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>a[i][j];
			if(a[i][j]=='.'){
				x=i;
				y=j;
				cnt++;
			}
		}
	}
	//cout<<cnt<<endl;
	memset(vis,false,sizeof(vis));
	dfs(x,y);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(vis[i][j] || a[i][j]=='#')
				cout<<a[i][j];
			else
				cout<<"X";
		}
		cout<<endl;
	}

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
