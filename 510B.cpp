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
const ll nax=69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll n,m;
char a[nax][nax];
bool vis[nax][nax];
bool check=false;
void dfs(ll i,ll j,ll cnt,ll previ,ll prevj){
	vis[i][j]=true;
	cnt++;
	//cout<<i<<' '<<j<<' '<<cnt<<endl;
	if(i<n-1 && a[i+1][j]==a[i][j]){
		if(cnt>=4 && vis[i+1][j] && i+1!=previ){
			check=true;
		}
		else if(!vis[i+1][j]) dfs(i+1,j,cnt,i,j);
	}
	if(i>0 && a[i-1][j]==a[i][j] && i-1!=previ){
		if(cnt>=4 && vis[i-1][j]){
			check=true;
		}
		else if(!vis[i-1][j]) dfs(i-1,j,cnt,i,j);
	}
	if(j<m-1 && a[i][j+1]==a[i][j] && j+1!=prevj){
		if(cnt>=4 && vis[i][j+1]){
			check=true;
			return;
		}
		else if(!vis[i][j+1])dfs(i,j+1,cnt,i,j);
	}
	if(j>0 && a[i][j-1]==a[i][j] && j-1!=prevj){
		if(cnt>=4 && vis[i][j-1]){
			check=true;
			return;
		}
		else if(!vis[i][j-1])dfs(i,j-1,cnt,i,j);
	}
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
    			dfs(i,j,0,i,j);
    		//	cout<<endl;
    		}
    		if(check)
    			break;
    	}
    	if(check)
    		break;
    }
    if(check)
    	cout<<"Yes"<<endl;
    else
    	cout<<"No"<<endl;
    
    
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
