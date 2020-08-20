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
const ll nax=1e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
void solve(){
	ll n,k;
	cin>>n>>k;
	vector<ll> dp(n+1,inf),a(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	dp[0]=k;
	for (int i = 1; i < n; ++i)
	{
		dp[i]=dp[i-1]+k;
		vector<ll> cnt(101,0);
		cnt[a[i]]++;
		for (int j = i-1; j >= 0; --j)
		{
			cnt[a[j]]++;
			ll val = 0;
			for(auto x : cnt)
				if(x>1)
					val+=x;
			if(j)
				dp[i]=min(dp[i],dp[j-1]+k+val);
			else
				dp[i]=min(dp[i],k+val);
		}
	}
	cout<<dp[n-1]<<endl;
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
