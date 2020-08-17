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
const ll nax=2e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll h[nax],s[nax],a[nax],dp[nax];
bool customsort(const pii &a, const pii &b){
	if(a.second!=b.second)
		return a.second>b.second;
	return a.first>b.first;
}
void solve(){
	ll n,m,x;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		dp[i]=0;
	}
	dp[n]=dp[n+1]=0;
	cin>>m;
	for (int i = 0; i < m; ++i)
	{
		cin>>h[i]>>s[i];
		dp[s[i]]=max(dp[s[i]],h[i]);
	}
	ll curr=0;
	for (int i = n-1; i >= 0; --i)
	{
		dp[i]=max(dp[i],dp[i+1]);
	}
	ll ans=0;
	bool check=true;
	ll ind=0;
	while(ind<n)
	{
		ll curr=ind,mx=0;
		while(1){
			mx=max(a[curr],mx);
			if(dp[curr-ind+1]<mx)
				break;
			++curr;
		}
		if(ind==curr){
			check=false;
			break;
		}
		ind=curr;
		++ans;
	}
	if(check)
		cout<<ans<<endl;
	else
		cout<<-1<<endl;
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