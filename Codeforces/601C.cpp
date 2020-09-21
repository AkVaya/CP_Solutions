#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<queue>
#include<iomanip>
#define endl '\n'
#define pb emplace_back
#define ins insert 
#define Fir first
#define Sec second
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
using namespace std;
typedef long long ll ;
using pii = pair<ll,ll>;
const ll M =1e9+7;
const ll nax=4e2+69;
bool adj[nax][nax];
void solve(){
	ll n,m,x,y;
	cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		cin>>x>>y;
		adj[x][y]=1;
		adj[y][x]=1;
	}
	vector<bool> vis(n+1,false);
	vector<ll> lvl(n+1,0);
	lvl[n]=-1;
	if(adj[1][n]){
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				adj[i][j]=1-adj[i][j];
			}
		}
	}
	queue<ll> q;
	q.push(1);
	vis[1]=true;
	while(q.size()){
		ll v=q.front();
		q.pop();
		//cout<<v<<' ';
		for (int i = 1; i <= n; ++i)
		{
			if(adj[v][i] && !vis[i]){
				vis[i]=true;
				lvl[i]=1+lvl[v];
				q.push(i);
			}
		}
	}
	cout<<lvl[n]<<endl;

	
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    //cin>>t;
    //clock_t t3 = clock();
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
   // cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
   // cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}
