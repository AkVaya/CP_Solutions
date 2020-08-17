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
const ll nax=1e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll dp[nax][6];
vector<bool> v(nax,true);
vector<ll> cnt(nax,0);
void sieve(){
	cnt[0]=cnt[1]=0;
	for (int i = 2; i < nax; i+=2)
	{
		cnt[i]++;
		v[i]=false;
	}
	for (ll i = 3; i < nax; i+=2)
	{
		if (v[i])
		{
			for (ll j = i; j < nax; j+=i)
			{
				cnt[j]++;
				v[j]=false;
			}
		}
	}
}
void solve(){
	ll a,b,k;
	cin>>a>>b>>k;
	cout<<dp[b][k]-dp[a-1][k]<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //#ifndef ONLINE_JUDGE 
      //  freopen("input.txt", "r", stdin); 
      //  freopen("output.txt", "w", stdout); 
    //#endif 
    sieve();
    for (int i = 1; i < 6; ++i)
    {
    	for (int j = 2; j < nax; ++j)
    	{
    		dp[j][i]=dp[j-1][i];
    		if(cnt[j]==i){
    			//cout<<i<<' '<<j<<endl;
    			dp[j][i]++;
    		}
    	}
    }
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