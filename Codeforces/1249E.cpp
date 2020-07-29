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
const ll nax=2e5+69;
const ll inf=1e18;
using pii = pair<ll,ll>;
ll dp[nax][2];// 1 matlab last step was through the elevator
void solve(){
	ll n,c;
	cin>>n>>c;
	ll a[n],b[n];
	for (int i = 1; i < n; ++i)
	{
		cin>>a[i];
		dp[i][0]=dp[i][1]=M;
	}
	for (int i = 1; i < n; ++i)
	{
		cin>>b[i];
	}
	dp[0][0]=0;
	dp[0][1]=c;
	cout<<0<<' ';
	for (int i = 1; i < n; ++i)
	{
		dp[i][0]=min(dp[i-1][0]+a[i],dp[i-1][1]+a[i]);
		dp[i][1]=min(dp[i-1][0]+b[i]+c,dp[i-1][1]+b[i]);
		cout<<min(dp[i][1],dp[i][0])<<' ';
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