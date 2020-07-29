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
#include<bitset>
//#define endl '\n'
#define Fi first
#define Se second
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
const ll nax=1e3+69;
const ll inf=1e18;
using pii = pair<ll,ll>;
ll pref[nax][2];
void solve(){
	ll n,m,x,y;
	cin>>n>>m>>x>>y;
	char a[n][m];
	ll dp[m+1][2];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>a[i][j];
			if(a[i][j]=='#')
				pref[j+1][1]++;
			else
				pref[j+1][0]++;
			dp[j][0]=dp[j][1]=inf;
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		pref[i][0]+=pref[i-1][0];
		pref[i][1]+=pref[i-1][1];
		//cout<<pref[i][0]<<" "<<pref[i][1]<<endl;
	}
	dp[m][0]=dp[m][1]=inf;
	dp[0][0]=dp[0][1]=0;
	for (int i = 0; i < m; ++i)
	{
		for (int k = x; k <= y && i+k<=m; ++k)
		{
			dp[i+k][0]=min(dp[i+k][0],dp[i][1]+pref[i+k][0]-pref[i][0]);
			dp[i+k][1]=min(dp[i+k][1],dp[i][0]+pref[i+k][1]-pref[i][1]);
		}
		//cout<<dp[i][0]<< " "<<dp[i][1]<<endl;
	}
	cout<<min(dp[m][0],dp[m][1])<<endl;
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