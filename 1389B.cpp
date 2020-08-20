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
const ll nax=5e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll dp[nax][6],a[nax],n,k,z;
ll fun(ll idx,ll cntk,ll cnt){
	if(cntk>k || cnt>z || idx>n || idx<1 )
		return 0;
	if(dp[cntk][cnt]!=-1)
		return dp[cntk][cnt];
	ll temp = max(a[idx]+fun(idx+1,cntk+1,cnt),a[idx]+fun(idx-1,cntk+1,cnt+1));
	dp[cntk][cnt]=temp;
	return temp;
}
void solve(){
    cin>>n>>k>>z;
    for (int i = 0; i <= k; ++i)
    {
    	for (int j = 0; j <= z; ++j)
    	{
    		dp[i][j]=-1;
    	}
    }
    for (int i = 1; i <= n; ++i)
    {
    	cin>>a[i];
    }
    fun(2,1,0);
    //for (int i = 0; i <= k; ++i)
    //{
    //	for (int j = 0; j <= z; ++j)
    //	{
    //		cout<<dp[i][j]<<' ';
    //	}
    //	cout<<endl;
    //}
    ll ans = 0;
    for (int i = 0; i <= z; ++i)
    {
    	ans=max(ans,a[1]+dp[1][i]);
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
